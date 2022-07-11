#include<bits/stdc++.h>
#include<conio.h> 
#include<io.h>  
#include<iostream> 
#include<fstream>
#include<direct.h>

using namespace std;
 
stringstream temp_ss;
string Txtname;
struct Book_
{
    char ISBN[100];
    char name[100];
    char author[10];
    char press[100];
    int price;
    int sum;
};
struct  ArrayBooks
{
    struct Book_ Book[100];
    int length;
};

void creatFile(); 
void creatCsv(); 
void creatTxt(string Txtname);
void addBook(ArrayBooks *abs);
void removeBook(ArrayBooks *abs);
void renewBook(ArrayBooks *abs);
void showBook(ArrayBooks *abs); 
void queryBook(ArrayBooks *abs); 
void menu();
void end();

int main()
{
	creatFile();
	creatCsv();
    system("color F9");
    system("mode con cols=44 lines=21");
    int num;
    ArrayBooks abs;
    abs.length = 0;
    do{
        system("cls");
        menu();
        num = _getch();
        switch(num-48)
        {
            case 1:addBook(&abs);break;
            case 2:removeBook(&abs);break;
            case 3:renewBook(&abs);break;
            case 4:showBook(&abs);break;
            case 5:queryBook(&abs);break;
            case 0:end();break;
        }
    }while(num!=0);
}

void creatFile() 
{
	string path = "C://BOOK";
	if (_access(path.c_str(), 0) == -1)
	{
		int i = mkdir(path.c_str());
	}
}

void creatCsv()
{
	string path = "C:\\BOOK\\BOOK.txt";
	fstream fp(path.c_str(), ios::out);
	fp<<"ISBN,����,����,������,�۸�,����\n"; 
	fp.close();
}

void addBook(ArrayBooks *abs)
{
	int a;
	do{
	system("cls"); 
	cout << "�������鼮��ISBN��: " << endl;
    cin>>abs->Book[abs->length].ISBN;
    cout << "�������鼮������: " << endl;
    cin>>abs->Book[abs->length].name;
    cout << "�������鼮������: " << endl;
    cin>>abs->Book[abs->length].author;
    cout << "�������鼮�ĳ�����: " << endl;
    cin>>abs->Book[abs->length].press;
    cout << "�������鼮�ļ۸�: " << endl;
    cin>>abs->Book[abs->length].price;
    cout << "�������鼮������: " << endl;
    cin>>abs->Book[abs->length].sum;  
    abs->length++;
	char str[100] = "C:\\BOOK\\%s.txt";
	sprintf(str,"C:\\BOOK\\%s.txt",abs->Book[abs->length-1].name);
    fstream fp(str,ios::out);
    fstream fb("C:\\BOOK\\BOOK.txt",ios::out|ios::app);
    if (!fp){
        cout << "¼��ʧ��"<<endl;
    }
    fp <<"ISBN��: "<< abs->Book[abs->length-1].ISBN <<"\n"<<"����:  "<< abs->Book[abs->length-1].name<<"\n"<<"����:  "<< abs->Book[abs->length-1].author<<"\n"<<"������:  "<< abs->Book[abs->length-1].press<<"\n"<<"�۸�:  "<< abs->Book[abs->length-1].price<<"\n"<<"����:  "<< abs->Book[abs->length-1].sum<<"\n";
    fb<<abs->Book[abs->length-1].ISBN<<","<<abs->Book[abs->length-1].name<<","<<abs->Book[abs->length-1].author<<","<<abs->Book[abs->length-1].press<<","<<abs->Book[abs->length-1].price<<","<<abs->Book[abs->length-1].sum<<"\n";
	fp.close();
    fb.close();
    system("C:\\BOOK\\BOOK.txt");
    cout<<"¼��ɹ�"<<endl;
    cout<<"�Ƿ���� 1���� 0����"<<endl;
	a = _getch();
	}while(a-48==1);
}

void removeBook(ArrayBooks *abs)
{
	int a,f=0;
	do{
	system("cls");
	char sname[100];
	cout<<"��������Ҫɾ����ͼ������"<<endl;	
	cin>>sname;
	for(int i=0;i<abs->length;i--){
		if(strcmp(abs->Book[i].name,sname) == 0){
			for(int j=i;j<abs->length;j++){
				abs->Book[j] = abs->Book[j+1];
			}
			abs->length--;
			break;
		}
	}
	char str[100] = "C:\\BOOK\\%s.txt";
	fstream fb("C:\\BOOK\\BOOK.txt",ios::out);
	fb<<"ISBN,����,����,������,�۸�,����\n";
	for(int i=0;i<abs->length;i++){
		fb<<abs->Book[i].ISBN<<","<<abs->Book[i].name<<","<<abs->Book[i].author<<","<<abs->Book[i].press<<","<<abs->Book[i].price<<","<<abs->Book[i].sum<<"\n";
	}
	fb.close();
	sprintf(str,"C:\\BOOK\\%s.txt",sname);
	char *path = str;
	if(remove(path) == 0){	
		cout<<"ɾ���ɹ�"<<endl;
	} 
	else {
		cout<<"ɾ��ʧ��"<<endl; 
	}
	system("C:\\BOOK\\BOOK.txt"); 
    cout<<"�Ƿ���� 1���� 0����"<<endl;
	a = _getch(); 
	}while(a-48==1);
}

void renewBook(ArrayBooks *abs)
{
	int a,f=0;
	do{
		system("cls");
		cout<<"����Ҫ���ĵ�ͼ���ISBN�������"<<endl; 
		char s[100];
		do{
		cin>>s;
		for(int i=0;i<abs->length;i++){
			if(strcmp(abs->Book[i].ISBN,s)==0 || strcmp(abs->Book[i].name,s)==0){
				f = 1;
				cout<<"��Ҫ���ĵ���Ϣ:"<<endl;
				cin>>s;
				cout<<"��������ĺ����Ϣ��ISBN,����,����,������,�۸�,������";
				if(strcmp("����",s)==0){
					cout<<"��������ĺ������:"<<endl; 
					cin>>abs->Book[i].name;
				}
				else if(strcmp("ISBN",s)==0){
					cout<<"��������ĺ��ISBN��:"<<endl; 
					cin>>abs->Book[i].ISBN;
				}
				else if(strcmp("������",s)==0){
					cout<<"��������ĺ�ĳ�����:"<<endl; 
					cin>>abs->Book[i].press;
				}
				else if(strcmp("����",s)==0){
					cout<<"��������ĺ������:"<<endl; 
					cin>>abs->Book[i].author;
				}
				else if(strcmp("�۸�",s)==0){
					cout<<"��������ĺ�ļ۸�:"<<endl; 
					cin>>abs->Book[i].price; 
				}
				else{
					cout<<"��������ĺ������:"<<endl; 
					cin>>abs->Book[i].sum;
				}
			}
		} 
		if(f==0)cout<<"δ�ҵ�����������,����������"<<endl; 
		}while(f == 0);
		fstream fb("C:\\BOOK\\BOOK.txt",ios::out);
		fb<<"ISBN,����,����,������,�۸�,����\n";
		for(int i=0;i<abs->length;i++){
			fb<<abs->Book[i].ISBN<<","<<abs->Book[i].name<<","<<abs->Book[i].author<<","<<abs->Book[i].press<<","<<abs->Book[i].price<<","<<abs->Book[i].sum<<"\n";
		}
		fb.close();
		cout<<"�Ƿ���� 1���� 0����"<<endl;
		a = _getch();
	}while(a-48==1);
}

void showBook(ArrayBooks *abs)
{	
	int a;
	system("cls");
	if(abs->length>0){
	for(int i=0;i<abs->length;i++){
			cout<<"ISBN��: "<< abs->Book[i].ISBN <<"����:  "<< abs->Book[i].name<<"����:  "<< abs->Book[i].author<< "������:  "<< abs->Book[i].press<<"�۸�:  "<< abs->Book[i].price<<"����:  "<< abs->Book[i].sum<<"\n";	
	}
	}
	else cout<<"���ڻ�û����"<<endl; 
	cout<<"ȷ��"<<endl;
	a = _getch();
}
// 
void queryBook(ArrayBooks *abs)
{
	int a,f=0;
	do{
	system("cls");
	cout<<"����Ҫ���ҵ�ͼ���ISBN�������"<<endl; 
	char s[100];
	do{
	cin>>s;
	for(int i=0;i<abs->length;i++){
		if(strcmp(abs->Book[i].ISBN,s)==0 || strcmp(abs->Book[i].name,s)==0){
			f=1;
			cout<<"ISBN��: "<< abs->Book[i].ISBN <<"\n"<<"����:  "<< abs->Book[i].name<<"\n"<<"����:  "<< abs->Book[i].author<<"\n"<<"������:  "<< abs->Book[i].press<<"\n"<<"�۸�:  "<< abs->Book[i].price<<"\n"<<"����:  "<< abs->Book[i].sum<<"\n";
		}
	}
	if(f==0)cout<<"δ�ҵ�����������,����������"<<endl; 
	}while(f == 0);
	cout<<"�Ƿ���� 1���� 0����"<<endl;
	a = _getch();
	}while(a-48==1);
}
                   
void end()
{
	system("cls");
	cout<<"�Ƿ�ɾ������ͼ����Ϣ"; 
	system("del C:\\BOOK");
    exit(0);
}

void menu()
{
	cout<<endl; 
	cout<<"  ����������������������������������������  "<<endl;
	cout<<"  ��   \t\t\t\t        ��"<<endl;
    cout<<"  ��\t      "<<"ͼ�����ϵͳ"<<"\t        ��"<<endl;
    cout<<"  ��   \t\t\t\t        ��"<<endl;
    cout<<"  ��   \t\t\t\t        ��"<<endl;
    cout<<"  ��\t       "<<"1 ����ͼ�� "<<"\t        ��"<<endl;
    cout<<"  ��   \t\t\t\t        ��"<<endl;
    cout<<"  ��\t       "<<"2 ɾ��ͼ�� "<<"\t        ��"<<endl;
    cout<<"  ��   \t\t\t\t        ��"<<endl; 
    cout<<"  ��\t       "<<"3 ����ͼ�� "<<"\t        ��"<<endl;
    cout<<"  ��   \t\t\t\t        ��"<<endl;
    cout<<"  ��\t       "<<"4 ͼ���� "<<"\t        ��"<<endl;
    cout<<"  ��   \t\t\t\t        ��"<<endl;
    cout<<"  ��\t       "<<"5 ��ѯͼ�� "<<"\t        ��"<<endl;
    cout<<"  ��   \t\t\t\t        ��"<<endl;
    cout<<"  ��         "<<"��Ҫִ�еĲ���(1-5)"<<"        ��"<<endl;
    cout<<"  ��   \t     �� 0�˳�ϵͳ ) \t        ��"<<endl;
    cout<<"  ��   \t\t\t\t        ��"<<endl;
    cout<<"  ����������������������������������������";
}
/* 

001
���������塷 
�޹��� 
���������
19
1 

002
��ˮ䰴���
ʩ����
���������
19
1

003
�����μǡ�
��ж�
���������
19
1

004
����¥�Ρ�
��ѩ��
���������
19
1 
*/
