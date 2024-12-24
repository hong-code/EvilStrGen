# EvilStrGen

[![Awesome](https://awesome.re/badge.svg)](https://awesome.re) 
![Static Badge](https://img.shields.io/badge/Security_ReDoS-blue)
![Static Badge](https://img.shields.io/badge/Non_backtracking_RegexEngine-green)
![Static Badge](https://img.shields.io/badge/to_be_continue-orange)

🌈 The implementation of EvilStrGen, described in USENIX Security 2024 "Towards an Effective Method of ReDoS Detection for Non-backtracking Engines".


## Introduction

We walk through the procedure of ReDoS detection in EVILSTRGEN. The input of EVILSTRGEN includes the regex, the expec-ted attack string length, the matching function and the engine.


The tool first preprocesses the input, e.g. for the functions using the mechanic of unanchored partial matching, a Σ∗ is prepe-nded to the input regex as in [60], etc., in step 1 of Figure below. Next, the tool calls the k-SIMPLE STRING solver INC_DET′ to generate ReDoS attack strings bytewise with incremental determinisation based on the DFA in the corresponding engine. 

The search for k-simple strings uses two complete and an incomplete strategy to optimize its efficacy. Step 2, the first strate-gy exploits the power of nondeterminism in automata theory to select the symbols that results in the largest DFA states in at-tack strings. The second strategy, i.e. step 3,mimics the Perl-style disambiguation rules to select the DFA
state with the highe-st matching priority. 

When a considerable amount of conflicts (see §5.2) is detected, step 4 uses an incomplete non-chronological backtracking to prune the state space.

When the solver terminates, it outputs a k-simple string or a currently longest simple string in step 5. 

Next in step 6, considering matching function, anchors and the size of the
simple string, EVILSTRGEN decides to go to the va-lidation,
or to step 7 to search repeatedly to obtain a candidate attack
string of proper length by appending outputs to the f-ormer
results. Finally in step 8, a validator is used to verify the
string according to the criteria for ReDoS on corresponding
e-ngines, and either reports the vulnerability with the effective
attack string or claims the regex safe.

Brief overview of EvilStrGen:

![OVERVIEW](https://github.com/hong-code/EvilStrGen/blob/main/assets/mechanics.png)


## Platform
- ubuntu20.04

- python: 3.x
  
- c++

## Create Environment

Now, let's start:

**Step 1:** Install [`gcc`][`g++`][`cmake`][`make`]

```bash
sudo apt install build-essential 
sudo apt install cmake
```


**Step 2:** Install [`python`] :

```bash
apt install python3.4
```


## How to run
```bash
cd EvilStrGen // Enter the root directory of the project
mkdir build && cd build // create build directory
cmake .. //load cmakelist file
make // compile into .exe file
./EvilStrGen [Regex] [OutputFile] [EngineType] [Attack String Length]
```

## Using multi-threaded Python scripts


```bash
python Batch_Processing.py
```


## Data Availability

For 5-way 1-shot exp., it allocates nearly 6GB GPU memory.

1. download `MiniImagenet` dataset from [here](https://github.com/dragen1860/LearningToCompare-Pytorch/issues/4), the splitted file: `train/val/test.csv` are provided in `data/split`
   
2. for image split, extract it like:

```shell
EvilStrGen/
├── regex_set #dataset
├── images
	├── n0210891500001298.jpg  
	├── n0287152500001298.jpg 
	...
├── test.csv
├── Batch_Processing.py
└── EvilStrGen.cpp  #main code

```


### Cite

If you find our work and codes useful, please consider citing our paper and star our repository (🥰🎉Thanks!!!):

```
@inproceedings {299724,
author = {Weihao Su and Hong Huang and Rongchen Li and Haiming Chen and Tingjian Ge},
title = {Towards an Effective Method of {ReDoS} Detection for Non-backtracking Engines},
booktitle = {33rd USENIX Security Symposium (USENIX Security 24)},
year = {2024},
isbn = {978-1-939133-44-1},
address = {Philadelphia, PA},
pages = {271--288},
url = {https://www.usenix.org/conference/usenixsecurity24/presentation/su-weihao},
publisher = {USENIX Association},
month = aug
}
```

