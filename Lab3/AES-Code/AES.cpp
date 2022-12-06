#include<iostream>
#include<string>
#include<map>
#include<stdio.h>
using namespace std;
//全局变量和常量
//密钥
string k[44];
string ming[4] = { "" };
string ci[4] = { "" };
//S盒
int S[16][16] = {
    0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
    0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
    0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
    0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
    0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
    0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
    0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
    0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
    0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
    0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
    0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
    0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
    0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
    0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
    0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
    0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
};
//逆S盒
int SR[16][16] = {
    0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
    0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
    0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
    0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
    0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
    0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
    0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
    0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
    0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
    0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
    0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
    0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
    0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
    0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
    0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
    0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d
};
//128bit检查
string cin_check(string a) {
    int len = a.length();
    //判断输入
    if (len > 32) { return 0; }
    if (len != 32) {
        for (int i = 0; i < 32 - len; i++) {
            a = "0" + a;
        }
    }
    for (int i = 0; i < 32; i++) {
        if (a[i] >= 97 && a[i] <= 122) {
            a[i] -= 32;
        }
    }
    cout << "检查输入:\t" << a <<"位数：\t"<<a.length() << endl;
    return a;
}
//字符串转十进制 一字节
int stode(string a) {
    map<char, int>mp_sh;
    mp_sh['0'] = 0;
    mp_sh['1'] = 1;
    mp_sh['2'] = 2;
    mp_sh['3'] = 3;
    mp_sh['4'] = 4;
    mp_sh['5'] = 5;
    mp_sh['6'] = 6;
    mp_sh['7'] = 7;
    mp_sh['8'] = 8;
    mp_sh['9'] = 9;
    mp_sh['A'] = 10;
    mp_sh['B'] = 11;
    mp_sh['C'] = 12;
    mp_sh['D'] = 13;
    mp_sh['E'] = 14;
    mp_sh['F'] = 15;
    mp_sh['a'] = 10;
    mp_sh['b'] = 11;
    mp_sh['c'] = 12;
    mp_sh['d'] = 13;
    mp_sh['e'] = 14;
    mp_sh['f'] = 15;
    return mp_sh[a[0]] * 16 + mp_sh[a[1]];

}
//字符转十进制
int ctode(char a) {
    map<char, int>mp_sh;
    mp_sh['0'] = 0;
    mp_sh['1'] = 1;
    mp_sh['2'] = 2;
    mp_sh['3'] = 3;
    mp_sh['4'] = 4;
    mp_sh['5'] = 5;
    mp_sh['6'] = 6;
    mp_sh['7'] = 7;
    mp_sh['8'] = 8;
    mp_sh['9'] = 9;
    mp_sh['A'] = 10;
    mp_sh['B'] = 11;
    mp_sh['C'] = 12;
    mp_sh['D'] = 13;
    mp_sh['E'] = 14;
    mp_sh['F'] = 15;
    mp_sh['a'] = 10;
    mp_sh['b'] = 11;
    mp_sh['c'] = 12;
    mp_sh['d'] = 13;
    mp_sh['e'] = 14;
    mp_sh['f'] = 15;
    return mp_sh[a];
}
//十六进制转字符串 一字节
string htos(int a) {
    int b = a / 16;
    int c = a % 16;
    map<int, string>mp_ic;
    mp_ic[0] = "0";
    mp_ic[1] = "1";
    mp_ic[2] = "2";
    mp_ic[3] = "3";
    mp_ic[4] = "4";
    mp_ic[5] = "5";
    mp_ic[6] = "6";
    mp_ic[7] = "7";
    mp_ic[8] = "8";
    mp_ic[9] = "9";
    mp_ic[10] = "A";
    mp_ic[11] = "B";
    mp_ic[12] = "C";
    mp_ic[13] = "D";
    mp_ic[14] = "E";
    mp_ic[15] = "F";
    string s = "";
    s += mp_ic[b];
    s += mp_ic[c];
    return s;
}
//十六进制转字符
string htoc(int a) {
    map<int, string>mp_ic;
    mp_ic[0] = "0";
    mp_ic[1] = "1";
    mp_ic[2] = "2";
    mp_ic[3] = "3";
    mp_ic[4] = "4";
    mp_ic[5] = "5";
    mp_ic[6] = "6";
    mp_ic[7] = "7";
    mp_ic[8] = "8";
    mp_ic[9] = "9";
    mp_ic[10] = "A";
    mp_ic[11] = "B";
    mp_ic[12] = "C";
    mp_ic[13] = "D";
    mp_ic[14] = "E";
    mp_ic[15] = "F";
    return mp_ic[a];
}
//左移一位
string left_one(string a) {
    string b ="";
    for (int i = 2; i < 8; i++) {
        b += a[i];
    }
    b += a[0];
    b += a[1];
    //cout << "左移后：\t" << b << endl;
    return b;
}
//S盒置换
string key_S(string a) {
    string a1 = "";
    
    for (int i = 0; i < a.length(); i+=2) {
        a1 += htos(S[ctode((a[i]))][ctode((a[i+1]))]);
    }
    //cout << "S盒置换：\t" << a1 << endl;
    return a1;

}
//逆S盒置换
string key_SR(string a) {
    string a1 = "";

    for (int i = 0; i < a.length(); i += 2) {
        a1 += htos(SR[ctode((a[i]))][ctode((a[i + 1]))]);
    }
    //cout << "S盒置换：\t" << a1 << endl;
    return a1;

}
//常量表
static const string Rcon[10] = { 
    "01000000", "02000000",
    "04000000", "08000000",
    "10000000", "20000000",
    "40000000", "80000000",
    "1b000000", "36000000" };
//key和常量表异或
string key_xor(string a,int n) {
    string b = "";
    for (int i = 0; i < a.length(); i++) {
        string c = htoc(ctode(a[i]) ^ ctode(Rcon[n][i]));
        b += c;
    }
    //cout << "kr异或后：\t" << b<<endl;
    return b;
}
//key和key异或
string keys_xor(string k1, string k2) {
   
    string b = "";
   
    for (int i = 0; i < k1.length(); i++) {
        string c = htoc(ctode(k1[i]) ^ ctode(k2[i]));
        b += c;
       
    }
    cout << "keys异或后：\t" << b << endl;
    return b;
}
//T函数
string T(string a, int i) {
    a = left_one(a);
    a = key_S(a);
    a = key_xor(a, i);
    return a;
}
void Getkeys(string key) {
    key = cin_check(key);
    for (int i = 0; i < 4; i++) {
        k[i] = "";
        for (int j = i * 8; j < i * 8 + 8; j++) {
            k[i] += key[j];
        }
        //cout << "k[" << i << "]：" << k[i] << endl;
    }
    int o = 0;
    for (int i = 4; i < 44; i++) {
        if (i % 4 != 0) {
            //不是4的倍数
            k[i] = keys_xor(k[i - 4], k[i - 1]);
        }
        else {
            k[i] = keys_xor(k[i - 4], T(k[i - 1],o));
            o++;
        }
    }
    cout << "已生成44个密钥！" << endl;
}
void Printkeys() {
    for (int i = 0; i < 44; i++) {
        cout << "k[" << i << "]：\t" << k[i] << endl;
    }
}
string ming_xor(string a, string b) {
    string m[4] = {""};
    string f[4] = {""};
    for (int i = 0; i < 4; i++) {
        for (int j = i*2; j < i*2+1; j ++) {
            m[i] += a[j];
            m[i] += a[j + 1];
            f[i] += b[j];
            f[i] += b[j + 1];
        }
        //cout << "m[i]: " << m[i] << "  f[i]：" << f[i] << endl;
    }
    int c[4];
    //两两相乘 再相加
    for (int i = 0; i < 4; i++) {
        c[i] = stode(m[i]);
        if (f[i] == "01") { 
            //cout << "进入if(1)" << endl;  
            //cout << "c[i]" << c[i] << endl;
        }
        if (f[i] == "02") {
            //cout << "进入if(2)" << endl;
            c[i]=(c[i] << 1);
            //cout << "c[i]" << c[i] << endl;
            if (c[i] >= 256) {
                c[i] = c[i] & 0xff;
                //cout << "c[i]" << c[i] << endl;
                c[i] = c[i] ^ 0b00011011;
                //cout << "c[i]" << c[i] << endl;
            }
        }
        if (f[i] == "03") {
            //cout << "进入if(3)" << endl;
            int temp = c[i];
            c[i] = (c[i] << 1);
            //cout << "c[i]" << c[i] << endl;
            if (c[i] >= 256) {
                c[i] = c[i] & 0xff;
                //cout << "c[i]" << c[i] << endl;
                c[i] = c[i] ^ 0b00011011;
                //cout << "c[i]" << c[i] << endl;
            }
            c[i] = temp ^ c[i];
            //cout << "c[i]" << c[i] << endl;
        }
       

    }
   //还没相加
    int aq = c[0] ^ c[1] ^ c[2] ^ c[3];
    return htos(aq);

}

void AddRoundKey(int n) {
    //行数据
    cout << "轮密钥加:" << endl;
    int j = n * 4;
    for (int i = 0; i < 4; i++) {
        ming[i] = keys_xor(ming[i], k[j]);
        j++;
    }
}
void AddRoundKeyR(int n) {
    //行数据
    cout << "轮密钥加:" << endl;
    int j = n * 4;
    for (int i = 0; i < 4; i++) {
        ci[i] = keys_xor(ci[i], k[j]);
        j++;
    }
}
void AES_lock(string m) {
    cin >> m;
    m = cin_check(m);
    
    //行数据
    cout << "行数据" << endl;
    for (int i = 0; i < 4; i++) {
        ming[i] = "";
        for (int j = i * 8; j < i * 8 + 8; j++) {
            ming[i] += m[j];
        }
        cout << "ming[" << i << "]：" << ming[i] << endl;
    }
    cout << "ming[0].length()" << ming[0].length();
    AddRoundKey(0);

    //10轮
    for (int q = 1; q < 11; q++) {
        cout << "第" << q << "轮：" << endl;
        //S盒
        for (int i = 0; i < 4; i++) {
            ming[i] = key_S(ming[i]);
        }

        string ming_l[4] = { "" };
        //拿到列数据
        for (int n = 0; n < 4; n++) {
            //第n列
            for (int i = 0; i < 4; i++) {
                //第i行
                for (int j = n * 2; j < n * 2 + 2; j++) {
                    ming_l[n] += ming[i][j];
                }
            }
            cout << "ming_l[" << n << "]：" << ming_l[n] << endl;
        }

        //左移
        cout << "进行左移：" << endl;
        for (int i = 0; i < 4; i++) {
            int j = i;
            while (j != 0) {
                ming_l[i] = left_one(ming_l[i]);
                j--;
            }
            cout << ming_l[i] << endl;
        }

        //左移后结果
        cout << "左移后结果：" << endl;
        string ming_2[4];
        for (int n = 0; n < 4; n++) {
            //第n列
            for (int i = 0; i < 4; i++) {
                //第i行
                for (int j = n * 2; j < n * 2 + 2; j++) {
                    ming_2[n] += ming_l[i][j];
                }
            }
            cout << "ming_2[" << n << "]：" << ming_2[n] << endl;
        }

        
        //列混合
       
        string Mix[4] = {
           "02030101",
           "01020301",
           "01010203",
           "03010102"
        };
        cout << "将要进行列混淆：" << endl;


        string ming_3[4] = { "" };
        if (q == 10) {
            for (int n = 0; n < 4; n++) {
                //第n列
                for (int i = 0; i < 4; i++) {
                    //第i行
                    for (int j = n * 2; j < n * 2 + 2; j++) {
                        ming_3[n] += ming_2[i][j];
                    }
                }
                cout << "ming_3[" << n << "]：" << ming_3[n] << endl;
            }
        }
        else {
            for (int i = 0; i < 4; i++) {
                //第一行 mix 四列ming->第一行
                for (int j = 0; j < 4; j++) {
                    ming_3[i] += ming_xor(ming_2[j], Mix[i]);
                }
                cout << ming_3[i] << endl;
            }
        }
            
        //轮密钥加
        //列->行
        string ming_4[4] = { "" };
        for (int n = 0; n < 4; n++) {
            //第n列
            for (int i = 0; i < 4; i++) {
                //第i行
                for (int j = n * 2; j < n * 2 + 2; j++) {
                    ming_4[n] += ming_3[i][j];
                }
            }
            cout << "ming_4[" << n << "]：" << ming_4[n] << endl;
            ming[n] = ming_4[n];
        }
        cout << "将要轮密钥加：" << endl;
        AddRoundKey(q);

    }
 

}
void AES_unlock(string c) {
    cin >> c;
    c = cin_check(c);
    //轮密钥加
    AddRoundKeyR(40);

    for (int q = 9; q >= 0; q--) {





        //轮密钥加
        AddRoundKeyR(q);
    }


}
 

int main() {
	string c, m,key="";
    //得到44个密钥
	cin >> key;
    Getkeys(key);
    Printkeys();

    
    //明文
    AES_lock(m);
    cout << "得到密文：" << endl;
    for (int i = 0; i < 4; i++) {
        cout << ming[i] << endl;
    }

    //密文
    


  

   /* for (int i = 0; i < 4; i++) {
        int s = 0;
        for (int j = 0; j < 4 ; j++) {
            
            k2[i][j] = "";
            k2[i][j] += k[i][s];
            k2[i][j] += k[i][s+1];
            s += 2;
            k3[i][j] = stode(k2[i][j]);
            cout << k3[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 4; i < 44; i++) {
        Extend(k3[i]);
    }


    cout << int(101^int(10))<<endl;
    cout << (0x32 << 16) << endl;*/
}
