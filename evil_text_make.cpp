//
// Created by 黄鸿 on 2023/8/16.
//
#include <iostream>
#include "src/re2.h"
#include "src/prog.h"
#include "src/regexp.h"
#include "fstream"

//\w[s123456789qwertyuioasdfghjkzxcvbnASDFGHJQWERTYUZXCVBNMdacabcdcbmrtyw1248]
int main() {
    //std::ifstream read_regex;
    //read_regex.open("/home/huangh/PureEvilTxTGen/regex_set/snort.txt", std::ios::binary);
    //.*<hostname>\\w{250}
    //
    //src::RE2 t = src::RE2("[c=jk]*[c=j]c=[c=j]{20}");
    //re2::RE2 t = re2::RE2("^([0-9]{1,3}\\.){3}[0-9]{1,3}(\\/([0-9]|[1-2][0-9]|3[0-2]))?$");
//    re2::RE2 t = re2::RE2(".*[?&]sp[kh]=[^k]{256}$");
    //re2::RE2 t = re2::RE2(".*[09lpo]cbd=[^j]{100}$");
    //src::RE2 t = src::RE2(".*/<[^>]*?\\x25/ROsmi");
    //src::RE2 t = src::RE2(".*([\\xfc]).{0,50}([\\x27])([\\x20\\x26\\x3b\\x7c]|[\x3c\\x3e\\x24]\\x28)+");
    //re2::RE2 t = re2::RE2(".*A([a-zA-Z0-9-\\,\\s]{2,64})");
    //src::RE2 t = src::RE2(".*[abskdf]{10}s(abs|kdf){10}");
    //re2::RE2 t = re2::RE2("[^k]*(hostname|jlk)[^j]{100}kls");
    //re2::RE2 t = re2::RE2(".*includefile\\w{200}zk->/smi");
    //src::RE2 t = src::RE2("(a|b|c|d)*(a(b|c|d)(b|c|d)(b|c|d)|b(a|c|d)(a|c|d)(a|c|d)|c(a|b|d)(a|b|d)(a|b|d)|d(a|b|c)(a|b|c)(a|b|c))");
    //src::RE2 t = src::RE2("(a|b|c|d)*(a(b|c|d){40}|b(a|c|d){40}|c(a|b|d){40}|d(a|b|c){40})");
    //re2::RE2 t = re2::RE2("^([A-Z]*|([A-Z]\\d?){10,12}[A-Z])*$");
//    re2::RE2 t = re2::RE2(".*a[ab]{20}");
    //re2::RE2 t = re2::RE2("(a|b|c|d|e|f)*(a|b|c|d|e)(a|b|c|d|f)(a|b|d|e|f)(a|b|c|d|e|f)(a|b|c|d|e|f)(a|b|c|d|e|f)");
//    re2::RE2 t = re2::RE2("([0-9A-Za-z]+)(?:.{100})" );
//    re2::RE2 t = re2::RE2("(?i).*cc.*(cor.*ang.*|heart.*|icd.*|pace.*|coronary.*|cardi.*|aortic.*|lhc.*|.rhc.*|dual.*lead.*|cabg.*|trans.*echo.*)");
    //src::RE2 t = src::RE2(".*/w3who\\.dll\\x3F[^\\r\\n]{519}/i");
    //src::RE2 t = src::RE2("(a|b|abaaba)*");
    //re2::RE2 t = re2::RE2("ki(ac(ffgac)*f+g)*lks");
    //re2::RE2 t = re2::RE2(".*ba(a|b|abaaba)(a|b|abaaba)(a|b|abaaba)(a|b|abaaba)(a|b|abaaba)(a|b|abaaba)(a|b|abaaba)(a|b|abaaba)(a|b|abaaba)(a|b|abaaba)(a|b|abaaba)(a|b|abaaba)(a|b|abaaba)(a|b|abaaba)(a|b|abaaba)(a|b|abaaba)(a|b|abaaba)(a|b|abaaba)");
    //re2::RE2 t = re2::RE2("(ab+)+a\\w{50}");
    //re2::RE2 t = re2::RE2("");
    //re2::RE2 t = re2::RE2("^hostname([A-Za-z]*|([a-zA-Z]\\d*){100}[A-Za-z])*$");
    //re2::RE2 t = re2::RE2("/<\\w+\\x3afill\\s[^>]*method\\s*=\\s*(\\x27[^\\x27]{32}|\\x22[^\\x22]{32}|[^\\s>]{32})/smi");
    //re2::RE2 t = re2::RE2("(ac(ffgac)*f+g){100}");
    //re2::RE2 t = re2::RE2(".*username=[usernam=k]+opu");
    //re2::RE2 t = re2::RE2("\\w*b[^c]{10}huan");
    //std::cout <<  "sdf" << std::endl;
//    re2::Prog* P = t.RetProg();
//    P->Create_evil_text(re2::Prog::kFullMatch, re2::Prog::Deep_Find, re2::Prog::Non_Backtracking,100000,  "", 1, 8, "Out.txt");
    printf("begin");
    std::ifstream read_regex;
    read_regex.open("/tmp/tmp.eD3rNeRqBG/regex_set/qualified_regex_736562.txt", std::ios::binary);
    //input_regex.open(R"(D:\hhcode\PureEvilTxTGen\regex_set\qualified_regex.txt)");
    //.*<hostname>\\w{250}
    //src::RE2 t = src::RE2("\\w*b(b.){10}");
    //std::cout <<  "sdf" << std::endl;
    std::string regex;
    int k = 1;
//    while (getline(read_regex, regex)){
//        k++;
//        if (k == 96174)
//            break;
//    }

    while (getline(read_regex, regex)){
        k++;
        regex.pop_back();
        auto regex1 = regex;
        re2::RE2 t = re2::RE2(regex1);
        if (t.Ret_regex() == nullptr)
            continue;
        re2::Prog* P = t.RetProg();
        if (P == nullptr)
            continue;
        P->EvilStrGen(re2::Prog::kFullMatch, re2::Prog::ALLSTRAT_ON, re2::Prog::Java, 100000, regex, k, 1, "1");
    }
    std::cout << k << std::endl;
}
