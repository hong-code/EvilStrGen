import re
import os
import subprocess
import signal
import functools
from concurrent import futures
import time
import subprocess
import shutil
import sqlite3
import threading
from timeit import default_timer as timer
from concurrent.futures import ThreadPoolExecutor,as_completed
from tqdm import tqdm


length = 1024*1024*10
# ./Main regex.txt out.txt N 10000
commands = {
    "Main": "./Main",
    "Main800": "./Main800",
    "MainRandom800": "./MainRandom800",
    "X_Main": "./Main",
    "X_Main800": "./Main800",
    "X_MainRandom800": "./MainRandom800",
    "MainNew": "./MainNew",
}

# /usr/bin/time -f "%U\n%S\n%e\n%c\n%w" -o out.txt rust/target/release/benchmark "regex" attackstring.txt
time_command = '/usr/bin/time -f "%U\n%S\n%e\n%c\n%w" -o'
verify_command = 'timeout 600s home/hhuang/Engine_Test/rust/target/release/benchmark '


# 连接数据库
conn = sqlite3.connect('regexes.db')
# 创建游标
cursor = conn.cursor()
# # 新建表：int id, text method, float usertime, float systemtime, float realtime, int cycle, int IO
# cursor.execute('create table if not exists rust (id int, method text, usertime float, systemtime float, realtime float, cycle int, IO int)')
# 查询数据
cursor.execute('select id, regex from regexes')
# 获取查询结果
values = cursor.fetchall()

pbar = tqdm(total=len(values))

# 对单个正则进行测试
def run(id, regex):
  # 在Attack目录下创建文件夹
  attack_path = os.path.join('/RealWorld/Attack', str(id))
  if not os.path.exists(attack_path):
    os.makedirs(attack_path)
  # 创建正则文件
  with open(os.path.join(attack_path, 'regex.txt'), 'w') as f:
    f.write(regex)
  # 在Output目录下创建文件夹
  output_path = os.path.join('/RealWorld/Output', str(id))
  if not os.path.exists(output_path):
    os.makedirs(output_path)
  # 针对每个命令进行测试
  for command in commands:
    # 用命令生成攻击串，限时600s
    try:
      print(" ".join([commands[command], os.path.join(attack_path, 'regex.txt'), os.path.join(attack_path, command + '.txt'), 'N' if command[0] != 'X' else 'X', str(length)]))
      subprocess.run([commands[command], os.path.join(attack_path, 'regex.txt'), os.path.join(attack_path, command + '.txt'), 'N' if command[0] != 'X' else 'X', str(length)], timeout=600)

      # 用命令测试攻击串，将结果以命令和id命名保存在Output目录下，限时600s
      subprocess.run([time_command, os.path.join(output_path, command + '.txt'), verify_command, "\"" + regex + "\"", os.path.join(attack_path, command + '.txt')], timeout=700)
    except subprocess.TimeoutExpired:
      # 打印id和超时的命令
      print(id, command)
      # 在Output目录记录失败信息
      with open(os.path.join(output_path, command + '.txt'), 'w') as f:
        f.write('gen attack string timeout')
      continue
  
  # 更新进度条
  pbar.update(1)


thread_num = 1

# 对每个正则表达式进行测试
for value in values:
  with ThreadPoolExecutor(max_workers=thread_num) as executor:
    executor.submit(run, value[0], value[1])

# 关闭游标
cursor.close()
# 关闭连接
conn.close()


