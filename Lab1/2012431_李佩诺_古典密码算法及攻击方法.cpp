#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
int main() {
	cout << "a:��λ���� b:��λ���빥�� c:�����û� d:�����û�����"<<endl;
	string op;
	cin >> op;
	if (op == "a") {
		cout << "��λ����" << endl;
		int func ;
		cout << "1->���� 2->���� " << endl;
		cout << "������ʵ�ֹ��ܣ�";
		cin >> func;
		while (func == 1 || func == 2 ) {
			if (func == 1) {
				cout << "������Ҫ���ܵ����ݣ�\t";
				string a;
				getline(cin, a);
				getline(cin, a);
				//cout<<typeid(a[0]).name()<<endl;
				int len = a.length();
				int n1;//����nλ
				cout << "��������λλ����\t";
				cin >> n1;
				if (n1 >= 26) { n1 %= 26; }
				string* key1 = new string[len];
				cout << "���ܽ����\t\t";
				for (int i = 0; i < len; i++) {
					if (a[i] < 65 || (a[i] > 90 && a[i] < 97) || a[i]>122) { cout << a[i]; continue; }
					if (a[i] >= 65 && a[i] <= 90) { a[i] += 32; }
					if (a[i] + n1 > 122) { a[i] -= 26; }
					key1[i] = char(int(a[i]) + n1);
					cout << key1[i];
				}
				cout << endl;
				cout << "������ʵ�ֹ��ܣ�";
				cin >> func;
			}
			if (func == 2) {
				cout << "������Ҫ���ܵ����ݣ�\t";
				string a;
				getline(cin, a);
				getline(cin, a);
				int len = a.length();
				int n1;//����nλ
				cout << "��������λλ����\t";
				cin >> n1;
				if (n1 >= 26) { n1 %= 26; }
				string* key1 = new string[len];
				cout << "���ܽ����\t\t";
				for (int i = 0; i < len; i++) {
					if (a[i] < 65 || (a[i] > 90 && a[i] < 97) || a[i]>122) { cout << a[i]; continue; }
					if (a[i] >= 65 && a[i] <= 90) { a[i] += 32; }
					if (a[i] - n1 < 97) { a[i] += 26; }
					key1[i] = char(int(a[i]) - n1);
					cout << key1[i];
				}
				cout << endl;
				cout << "������ʵ�ֹ��ܣ�";
				cin >> func;
			}
		}
	}
	if (op == "b") {
		cout << "������Ҫ���ܵ����ݣ�\t";
		string b;
		getline(cin, b);
		getline(cin, b);
		int len = b.length();
		string* key1 = new string[len];
		for (int j = 1; j <= 26; j++) {
			cout << "��ԿΪ��" << j << "\t";
			for (int i = 0; i < len; i++) {
				string a = b;
				if (a[i] < 65 || (a[i] > 90 && a[i] < 97) || a[i]>122) { cout << a[i]; continue; }
				if (a[i] >= 65 && a[i] <= 90) { a[i] += 32; }
				if (a[i] - j < 97) { a[i] += 26; }
				key1[i] = char(int(a[i]) - j);
				cout << key1[i];
			}
			cout << endl;
		}
	}
	if (op == "c") {
		int func;
		cout << "1->���� 2->���� " << endl;
		cout << "������ʵ�ֹ��ܣ�";
		cin >> func;
		if (func == 1) {
			map<string, string>mp_str;
			map<char, char>mp_ch;
			string str1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			string str2 ;
			string key1="";
			cout << "������Կ��\t";
			getline(cin, str2);
			getline(cin, str2);
			map<char, int>mp_is;
			//����ĸ��������ĸ���ֱ�־λ����Ϊ0
			for (int i = 0; i < 26; i++) {
				mp_is[str1[i]] = 0;
			}
			//����������г��ֹ� ��־λ����Ϊ1 ��ley�����
			for (int i = 0; i < str2.length(); i++) {
				if (str2[i] >= 97 && str2[i] <= 122) { str2[i] -= 32; }
				else if (str2[i] < 65 || str2[i]>90) { continue; }
				if (mp_is[str2[i]] == 0) { key1 += str2[i]; }
				mp_is[str2[i]] = 1;
			}
			//û���ֹ��İ�˳������key��
			for (int i = 0; i < 26; i++) {
				if (mp_is[str1[i]] == 0) { key1 += str1[i]; }
			}
			cout << "��ԿΪ��\t" << key1 << endl;
			str2 = key1;
			//����ӳ���
			for (int i = 0; i < 26; i++) {
				mp_ch[str1[i]] = str2[i];
			}
			cout << "�������ģ�\t";
			string a;
			getline(cin, a);
			int len = a.length();
			string b = "";
			cout << "����Ϊ��\t";
			for (int i = 0; i < len; i++) {
				if (a[i] >= 97 && a[i] <= 122) { a[i] -= 32; cout << char((mp_ch[a[i]] + 32)); }
				else if (a[i] < 65 || a[i]>90) { cout << a[i]; }
				else { cout << mp_ch[a[i]]; }
			}
		}
		if (func == 2) {
			map<string, string>mp_str;
			map<char, char>mp_ch;
			string str1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			string str2;
			string key1 = "";
			cout << "������Կ��\t";
			getline(cin, str2);
			getline(cin, str2);
			map<char, int>mp_is;
			for (int i = 0; i < 26; i++) {
				mp_is[str1[i]] = 0;
			}
			for (int i = 0; i < str2.length(); i++) {
				if (str2[i] >= 97 && str2[i] <= 122) { str2[i] -= 32; }
				else if (str2[i] < 65 || str2[i]>90) { continue; }
				if (mp_is[str2[i]] == 0) { key1 += str2[i]; }
				mp_is[str2[i]] = 1;
			}

			for (int i = 0; i < 26; i++) {
				if (mp_is[str1[i]] == 0) { key1 += str1[i]; }
			}
			cout << "��ԿΪ��\t" << key1 << endl;
			str2 = key1;

			for (int i = 0; i < 26; i++) {
				mp_ch[str2[i]] = str1[i];
			}
			cout << "�������ģ�\t";
			string a;
			getline(cin, a);
			int len = a.length();
			string b = "";
			cout << "����Ϊ��\t";
			for (int i = 0; i < len; i++) {
				if (a[i] >= 97 && a[i] <= 122) { a[i] -= 32; cout << char((mp_ch[a[i]] + 32)); }
				else if (a[i] < 65 || a[i]>90) { cout << a[i]; }
				else { cout << mp_ch[a[i]]; }
			}
		}
		
	}
	if (op == "d") {
		cout << "�������ģ�";
		string a;
		getline(cin, a);
		getline(cin, a);
		string a_copy = a;
		int len = a.length();
		int sum = len;
		map<char, float>mp_cf;
		string str = "abcdefghijklmnopqrstuvwxyz";
		string str_c = str;
		//��ʼ��
		for (int i = 0; i < 26; i++) {
			mp_cf[str[i]] = 0;
		}

		for (int i = 0; i < len; i++) {
			//cout << "a[i]" << a[i] << endl;
			if (a[i] == 32) { cout << " "; sum--; continue; }
			if (a[i] >= 65 && a[i] <= 90) { a[i] += 32; }
			mp_cf[a[i]] += 1;
		}
		cout << endl;
		//ͳ�Ƴ���Ƶ��
		for (char i = 0; i < 26; i++) {
			mp_cf[str[i]] /= sum;
			cout << str[i] << ":" << mp_cf[str[i]] << endl;
		}
		//����
		for (int i = 0; i < 26 - 1; i++) {
			for (int j = 0; j < 26 - i -1; j++) {
				if (mp_cf[str[j]] < mp_cf[str[j + 1]]) {
					float temp_f= mp_cf[str[j]];
					char temp_c=str[j];

					str[j] = str[j + 1];
					mp_cf[str[j]] = mp_cf[str[j + 1]];
					
					str[j + 1] = temp_c;
					mp_cf[str[j + 1]] = temp_f;
				}
			}
		}
		cout << "----------------------------------"<<endl;
		for (char i = 0; i < 26; i++) {
			cout << str[i] << ":" << mp_cf[str[i]] << endl;
		}
		//�����ı���ĸƵ��ӳ��
		map<char, char> map_stos;
		string net_str = "etoiansrhlducmpyfgwbvkxjqz";
		for (char i = 0; i < 26; i++) {
			map_stos[str[i]] = net_str[i];
		}
		cout << "�û���Ϊ��" << endl;
		for (char i = 0; i < 26; i++) {
			cout << str_c[i] << " ";
		}
		cout << endl;
		for (char i = 0; i < 26; i++) {
			cout << map_stos[str_c[i]] << " ";
		}
		cout << endl << "���ܽ����" << endl;
		//�״�����
		a = a_copy;
		for (int i = 0; i < len; i++) {
			if (a[i] == 32) { cout << " "; sum--; continue; }
			if (a[i] >= 65 && a[i] <= 90) { a[i] += 32; }
			cout << map_stos[a[i]];
		}
		//����Ӣ��������������
		while (1) {
			char old1;
			char new1;
			cout <<endl<<"---------------------------------------------------" << endl;
			cout << "the first letter:";
			cin >> old1;
			cout << "the second letter:";
			cin >> new1;


			cout << "--------------" << endl;
			for (int i = 0; i < 26; i++) {
				if (map_stos[str[i]] == old1) { map_stos[str[i]] = new1; continue; }
				if (map_stos[str[i]] == new1) { map_stos[str[i]] = old1; continue; }
			}

			cout << "�û���Ϊ��" << endl;
			for (char i = 0; i < 26; i++) {
				cout << str_c[i] << " ";
			}
			cout << endl;
			for (char i = 0; i < 26; i++) {
				cout << map_stos[str_c[i]] << " ";
			}
			cout << endl << "���ܽ����" << endl;
			for (int i = 0; i < len; i++) {
				//cout << "a[i]" << a[i] << endl;
				if (a[i] == 32) { cout << " "; sum--; continue; }
				if (a[i] >= 65 && a[i] <= 90) { a[i] += 32; }
				cout << map_stos[a[i]];
			}


		}
	}
}


	


	