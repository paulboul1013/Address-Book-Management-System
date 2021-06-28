#include<iostream>
using namespace std;
#include<string>
#define MAX 1000
//設計聯繫人結構體
struct person {
	string m_name;
	int m_sex;//1:boy 2:girl
	int m_age;
	string m_phone;
	string m_addr;


 };
// 設計通訊錄結構體

struct addressbooks {
	//通訊錄保存聯繫人陣列
	struct person personarray[MAX];
	//通訊錄紀錄當前聯繫人數
	int m_size;
};

//1.添加聯繫人
void addperson(addressbooks* abs) {
	//判斷通訊錄是否滿，full就不添加
	if (abs->m_size == MAX) {
		cout << "通訊錄已滿，無法添加" << endl;
		return;
	}
	else {
		//添加具體聯繫人
		//姓名
		string name;
		cout << "請輸入姓名: " << endl;
		cin >> name;
		abs->personarray[abs->m_size].m_name = name;
		//性別
		cout << "請輸入性別: " << endl;
		cout << "1----boy" << endl;
		cout << "2---girl" << endl;
		int sex = 0;
		while (true) {//輸入非1，2的話，重新輸入
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personarray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "輸入有錯，重新輸入" << endl;
		}
		//年齡
		cout << "請輸入年齡: " << endl;
		int age = 0;
		cin >> age;
		abs->personarray[abs->m_size].m_age = age;
	
		//電話
		cout << "請輸入聯繫電話: " << endl;
		string phone;
		cin >> phone;
		abs->personarray[abs->m_size].m_phone = phone;

		//住址
		cout << "請輸入家庭住址: " << endl;
		string address;
		cin >> address;
		abs->personarray[abs->m_size].m_addr = address;

		//更新通訊錄人數
		abs->m_size++;

		cout << "添加成功" << endl;

		system("pause");
		system("cls");
	}
}
//2.顯示所有聯繫人
void showperson(addressbooks* abs) {
	//判斷人數是否為0，如果為0，提示紀錄為0
	//如果不為0，顯示聯繫人信息

	if (abs->m_size == 0) {
		cout << "當前的紀錄為空" << endl;
	}
	else {
		for (int i = 0; i < abs->m_size; i++) {
			cout << "姓名: " << abs->personarray[i].m_name <<"\t";
			cout << "性別: " << (abs->personarray[i].m_sex==1?"男":"女" )<< "\t";
			cout << "年齡: " << abs->personarray[i].m_age << "\t";
			cout << "電話: " << abs->personarray[i].m_phone << "\t";
			cout << "地址: " << abs->personarray[i].m_addr << endl;

		}
	}
	system("pause");
	system("cls");
}

//檢測人是否存在，如果存在，返回聯繫人所在陣列的位置，不存在返回-1
int isexit(addressbooks *abs,string name) {
	for (int i = 0; i < abs->m_size; i++) {
		if (abs->personarray[i].m_name == name) {
			return i;
		}
		return -1;
	}
}
//3.刪除聯繫人
void deleteperson(addressbooks* abs) {
	cout << "請輸入刪除聯繫人" << endl;
	string name;
	cin >> name;
	//ret==-1 未查到
	//ret!=1 查到
	int ret = isexit(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->m_size; i++) {
			//資料往前
			abs->personarray[i] = abs->personarray[i + 1];

		}
		abs->m_size--;//更新通訊錄人數
		cout << "刪除成功" << endl;

	}
	else{
		cout << "查無此人" << endl;
	}
	system("pause");
	system("cls");

}
//4.查找指定聯繫人
void findperson(addressbooks* abs) {
	cout << "請輸入你要查找的聯繫人" << endl;
	string name;
	cin >> name;

	//判斷指定聯繫人是否存在通訊錄中
	int ret=isexit(abs, name);
	if (ret != -1) {
		cout << "姓名: " << abs->personarray[ret].m_name << "\t";
		cout << "性別: " << (abs->personarray[ret].m_sex == 1 ? "男" : "女") << "\t";
		cout << "年齡: " << abs->personarray[ret].m_age << "\t";
		cout << "電話: " << abs->personarray[ret].m_phone << "\t";
		cout << "地址: " << abs->personarray[ret].m_addr << endl;

	}
	else {
		cout << "查無此人" << endl;
	}

	system("pause");
	system("cls");
}
//5.修改指定聯繫人
void modifyperson(addressbooks *abs) {
	cout << "請輸入你要修改的聯繫人" << endl;
	string name;
	cin >> name;
	int ret = isexit(abs, name);
	if (ret != -1) {
		string name;
		cout << "請輸入姓名: " << endl;
		cin >> name;
		abs->personarray[ret].m_name = name;
		//性別
		cout << "請輸入性別: " << endl;
		cout << "1----boy" << endl;
		cout << "2---girl" << endl;
		int sex = 0;
		while (true) {//輸入非1，2的話，重新輸入
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personarray[ret].m_sex = sex;
				break;
			}
			cout << "輸入有錯，重新輸入" << endl;
		}
		//年齡
		cout << "請輸入年齡: " << endl;
		int age = 0;
		cin >> age;
		abs->personarray[ret].m_age = age;

		//電話
		cout << "請輸入聯繫電話: " << endl;
		string phone;
		cin >> phone;
		abs->personarray[ret].m_phone = phone;

		//住址
		cout << "請輸入家庭住址: " << endl;
		string address;
		cin >> address;
		abs->personarray[ret].m_addr = address;


		cout << "修改成功" << endl;
	}
	else {
		cout << "查無此人" << endl;
	}
	system("pause");
	system("cls");
}
//6.清空資料
void clearperson(addressbooks* abs) {
	int select = 0;
	cout << "輸入1清空 或 輸入2不清空" << endl;
	cin >> select;
	abs->m_size = 0;
	if (select == 1) {
		cout << "通訊錄已清空" << endl;
	}
	else {
		system("pause");
		system("cls");
		return;
	}
	system("pause");
	system("cls");
}
//菜單介面
void showmenu() {
	cout << "*************************" << endl;
	cout << "***** 1. 添加聯繫人 *****" << endl;
	cout << "***** 2. 顯示聯繫人 *****" << endl;
	cout << "***** 3. 刪除聯繫人 *****" << endl;
	cout << "***** 4. 查找聯繫人 *****" << endl;
	cout << "***** 5. 修改聯繫人 *****" << endl;
	cout << "***** 6. 清空聯繫人 *****" << endl;
	cout << "***** 0. 退出通訊錄 *****" << endl;
	cout << "*************************" << endl;
}

int main() {

	//創建通訊錄結構變量
	addressbooks abs;
	//初始化通訊錄中當前人員
	abs.m_size = 0;

	int select = 0;

	while (true) {
		showmenu();

		cin >> select;

		switch (select) {
		case 1://1. 添加聯繫人
			addperson(&abs);//利用地址傳遞
			break;
		case 2://2. 顯示聯繫人
			showperson(&abs);
			break;
		case 3://3. 刪除聯繫人
		/* {
			cout << "請輸入刪除聯繫人姓名: " << endl;
			string name;
			cin >> name;
			if (isexit(&abs, name) == -1) {
				cout << "查無此人" << endl;
			}
			else {
				cout << "找到此人" << endl;
			}
		}*/
			deleteperson(&abs);
			break;
		case 4://4. 查找聯繫人
			findperson(&abs);
			break;
		case 5://5. 修改聯繫人
			modifyperson(&abs);
			break;
		case 6://6. 清空聯繫人
			clearperson(&abs);
			break;
		case 0://0. 退出通訊錄
			cout << "歡迎下次使用" << endl;
			return 0;
			break;
		default:
			break;
		}
	}


	return 0;
}