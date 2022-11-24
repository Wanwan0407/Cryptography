#include<iostream>
#include<string>
#include<map>
#include<stdio.h>
using namespace std;
//16轮密钥
string keys[16];
//左移位数
const int leftarr[16] ={
    1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1
};
//十六进制转二进制
string htob(string h) {

    //01AB
    string b;
    map<char, string>map_hb; 
    map_hb['0'] = "0000";
    map_hb['1'] = "0001";
    map_hb['2'] = "0010";
    map_hb['3'] = "0011";
    map_hb['4'] = "0100";
    map_hb['5'] = "0101";
    map_hb['6'] = "0110";
    map_hb['7'] = "0111";
    map_hb['8'] = "1000";
    map_hb['9'] = "1001";
    map_hb['A'] = "1010";
    map_hb['B'] = "1011";
    map_hb['C'] = "1100";
    map_hb['D'] = "1101";
    map_hb['E'] = "1110";
    map_hb['F'] = "1111";
    for (int i = 0; i < h.length(); i++) {
        if (h[i] >= 97 && h[i] <= 122) { h[i] -= 32; }
        b += map_hb[h[i]];
    }

    
    return b;
}
//二进制转十六进制
string btoh(string h) {

    //01AB
    string b="";
    map<string, char>map_hb;
    map_hb["0000"] = '0';
    map_hb["0001"] = '1';
    map_hb["0010"] = '2';
    map_hb["0011"] = '3';
    map_hb["0100"] = '4';
    map_hb["0101"] = '5';
    map_hb["0110"] = '6';
    map_hb["0111"] = '7';
    map_hb["1000"] = '8';
    map_hb["1001"] = '9';
    map_hb["1010"] = 'A';
    map_hb["1011"] = 'B';
    map_hb["1100"] = 'C';
    map_hb["1101"] = 'D';
    map_hb["1110"] = 'E';
    map_hb["1111"] = 'F';
    for (int i = 0; i < 16; i++) {
        string t = h.substr(4 * i, 4);
        b += map_hb[t];
    }
    return b;
   
}
//输入64bit数据检查
string cin_check(string a) {
    int len = a.length();
    //判断输入
    if (len > 16) { return 0; }
    if (len != 16) {
        for (int i = 0; i < 16 - len; i++) {
            a = "0" + a;
        }
    }
    cout << "检查输入:\t" << a << endl;
    return a;
}
//密钥选择置换1 64->56
string pc_1(string key) {
    //压缩置换
    int pc1[56] = {
    57,49,41,33,25,17,9,1,58,50,42,34,26,18,
    10,2,59,51,43,35,27,19,11,3,60,52,44,36,
    63,55,47,39,31,23,15,7,62,54,46,38,30,22,
    14,6,61,53,45,37,29,21,13,5,28,20,12,4
    };
 
    char k[56];
    for (int i = 0; i < 56; i++) {
        k[i] = key[pc1[i]-1];
    }
    string key_1 = "";
    for (int i = 0; i < 56; i++) {
        key_1 += k[i];
    }
    return key_1;
}
//密钥左移
string leftmove(string key,int b) {
    
    string a="";
    if (leftarr[b] == 1) {
        
        for (int i = 1; i < key.length(); i++) {
            a += key[i];
        }
        a += key[0];
    }
    else if (leftarr[b] == 2) {
        
        for (int i = 2; i < key.length(); i++) {
            a += key[i];
        }
        a += key[0];
        a += key[1];
    }
    //cout << "左移" << leftarr[b] << "位后：\t" << a << endl;

    return a;
}
//密钥选择置换2 56->48
string pc_2(string key) {
    //压缩置换2
    int pc2[48] = {
    14,17,11,24,1,5,3,28,15,6,21,10,
    23,19,12,4,26,8,16,7,27,20,13,2,
    41,52,31,37,47,55,30,40,51,45,33,48,
    44,49,39,56,34,53,46,42,50,36,29,32
    };
    char k[48];
    for (int i = 0; i < 48; i++) {
        k[i] = key[pc2[i]-1];
    }
    string key_1 = "";
    for (int i = 0; i < 48; i++) {
        key_1 += k[i];
    }
    return key_1;

}
//获得16轮密钥 存入keys[16]
void Getkeys(string key) {
    //密钥64->56
    key = pc_1(key);
   // cout << "pc1置换后：\t" << key << "   位数为" << key.length() << endl;

    //key分成左和右
    string key_l = key.substr(0, 28);
    string key_r = key.substr(28, 28);
    //cout << "左密钥：\t" << key_l << "   位数为" << key_l.length() << endl;
    //cout << "右密钥：\t" << key_r << "   位数为" << key_r.length() << endl;
    for (int num = 0; num < 16; num++) {
       // cout << "第" << num+1 << "次\t\t：" << endl;

        //移位
        key_l = leftmove(key_l, num);
        key_r = leftmove(key_r, num);
        key = key_l + key_r;
       // cout << "key_56：\t" << key << "   位数为" << key.length() << endl;

        //密钥56->48
        string key_48 = "";
        key_48 += key_l;
        key_48 += key_r;

        //子密钥k1
        key_48 = pc_2(key_48);
        keys[num] = key_48;
        //cout << "密钥key："<<num+1<<"\t" << key_48 << "   位数为" << key_48.length() << endl;
       
    }

}
//初始置换IP
string IP(string ming) {
    //初始置换IP表
    const int iptable[64] = {
        58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,
        62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,
        57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,
        61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7
    };

    char k[64];
    for (int i = 0; i < 64; i++) {
        k[i] = ming[iptable[i] - 1];
    }
    string key_1 = "";
    for (int i = 0; i < 64; i++) {
        key_1 += k[i];
    }
    return key_1;
}
//E盒扩展
string E(string ming) {
    const int etable[48] =
    {
        32,1,2,3,4,5,4,5,6,7,8,9,
        8,9,10,11,12,13,12,13,14,15,16,17,
        16,17,18,19,20,21,20,21,22,23,24,25,
        24,25,26,27,28,29,28,29,30,31,32,1
    };
    char k[48];
    for (int i = 0; i < 48; i++) {
        k[i] = ming[etable[i] - 1];
    }
    
    string key_1 = "";
    for (int i = 0; i < 48; i++) {
        key_1 += k[i];
    }
    
    return key_1;

}
//异或
string Xor (string ming,string key) {
    string res = "";
    for (int i = 0; i < ming.length(); i++) {
        if (((int(ming[i] - 48))^(int(key[i] - 48)) )== 1) { res += "1"; }
        else { res += "0"; }
    }
    return res;
}
//二进制字符串转十进制整数
int bstod(string str) {
    int len = str.length();
    int n = stoi(str);//101
    int sum = 0;
    for (int i = 0; i < len; i++) {
        int t = n % 10;
        sum += t * pow(2, i);
        n /= 10;
    }
    return sum;
}
//十进制整数转四位二进制字符串
string dtobs(int a) {
    string res = "";
    while (a != 0) {
        int b = a % 2;
        if (b == 1) { res = "1" + res; }
        else { res = "0" + res; }
        a /= 2;
    }
    while (res.length() < 4) {
        res = "0" + res;
    }    
    return res;

}
//S盒
string S(string ming) {
    int stable[8][4][16] = {
        //S1
        {{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
        {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
        {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
        {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}},
        //S2
        {{15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},
        {3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
        {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
        {13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}},
        //S3
        {{10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},
        {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
        {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},
        {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}},
        //S4
        {{7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},
        {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
        {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
        {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}},
        //S5
        { {2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},
        {14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
        {4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},
        {11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}},
        //S6
        { {12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},
        {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
        {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
        {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}},
        //S7
        {{4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},
        {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
        {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
        {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}},
        //S8
        {{13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},
        {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
        {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
        {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}}
    };
    string m[8];
    string res="";
    map<string, int>mp_si;
    

    for (int i = 0; i < 8; i++) {
        string x = "";
        string y = "";
        m[i]= ming.substr(6*i, 6);
        x.append(1,m[i][0]).append(1,m[i][5]);
        y.append(1, m[i][1]).append(1, m[i][2]).append(1, m[i][3]).append(1, m[i][4]);
       // cout <<endl<< x << endl << y ;
        //在S盒中找到的xxxx
        int s = stable[i][bstod(x)][bstod(y)];
        res += dtobs(s);
    }
   
    //cout <<"S盒" << res << "位数" << res.length() << endl;
    return res;
}
//P置换
string P(string ming) {
    int ptable[32] =
    {
        16,7,20,21,29,12,28,17,1,15,23,26,5,18,31,10,
        2,8,24,14,32,27,3,9,19,13,30,6,22,11,4,25
    };
    char k[32];
    for (int i = 0; i < 32; i++) {
        k[i] = ming[ptable[i] - 1];
    }
    string key_1 = "";
    for (int i = 0; i < 32; i++) {
        key_1 += k[i];
    }
    return key_1;
}
//轮函数
string F(string ming_r,int i) {
    //右边进入轮函数
    ming_r = E(ming_r);
    //与当前轮密钥异或
    ming_r = Xor(ming_r, keys[i]);
    //S盒压缩
    ming_r = S(ming_r);
    //P置换
    ming_r = P(ming_r);
    return ming_r;

}
//逆置换
string IPR(string ming) {
    //逆初始置换IPR表
    const int iprtable[64] = {
        40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,
        38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,
        36,4,44,12,52,20,60,28,35,3,43,11,51,19,59,27,
        34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25
    };
    char k[64];
    for (int i = 0; i < 64; i++) {
        k[i] = ming[iprtable[i] - 1];
    }
    string key_1 = "";
    for (int i = 0; i < 64; i++) {
        key_1 += k[i];
    }
    return key_1;
}

int main() {

    //输入密钥
    string c;
    cout << "输入密钥：\t";
    cin >> c;
    c = cin_check(c);
    //得到了十六轮密钥
    string key = htob(c);
    Getkeys(key);

    //输入明文
    string a;
    cout << "输入明文：\t";
    cin >> a;
    a = cin_check(a);
    string ming = IP(htob(a));
    //cout << "ip置换后：\t" << ming << "   位数为" << ming.length() << endl;

    string ming_l = ming.substr(0, 32);
    string ming_r = ming.substr(32, 32);
    string temp_ming_r = ming_r;

    for (int i = 0; i < 16; i++) {
        ming_r = Xor(F(ming_r,i), ming_l);
        ming_l = temp_ming_r;
        temp_ming_r = ming_r;
    }
    ming = ming_r;
    ming += ming_l;
    ming = IPR(ming);

    cout << "获得密文：\t" << btoh(ming) << endl;
}