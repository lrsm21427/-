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
	fp<<"ISBN,书名,作者,出版社,价格,数量\n"; 
	fp.close();
}

void addBook(ArrayBooks *abs)
{
	int a;
	do{
	system("cls"); 
	cout << "请输入书籍的ISBN码: " << endl;
    cin>>abs->Book[abs->length].ISBN;
    cout << "请输入书籍的名称: " << endl;
    cin>>abs->Book[abs->length].name;
    cout << "请输入书籍的作者: " << endl;
    cin>>abs->Book[abs->length].author;
    cout << "请输入书籍的出版社: " << endl;
    cin>>abs->Book[abs->length].press;
    cout << "请输入书籍的价格: " << endl;
    cin>>abs->Book[abs->length].price;
    cout << "请输入书籍的数量: " << endl;
    cin>>abs->Book[abs->length].sum;  
    abs->length++;
	char str[100] = "C:\\BOOK\\%s.txt";
	sprintf(str,"C:\\BOOK\\%s.txt",abs->Book[abs->length-1].name);
    fstream fp(str,ios::out);
    fstream fb("C:\\BOOK\\BOOK.txt",ios::out|ios::app);
    if (!fp){
        cout << "录入失败"<<endl;
    }
    fp <<"ISBN码: "<< abs->Book[abs->length-1].ISBN <<"\n"<<"书名:  "<< abs->Book[abs->length-1].name<<"\n"<<"作者:  "<< abs->Book[abs->length-1].author<<"\n"<<"出版社:  "<< abs->Book[abs->length-1].press<<"\n"<<"价格:  "<< abs->Book[abs->length-1].price<<"\n"<<"数量:  "<< abs->Book[abs->length-1].sum<<"\n";
    fb<<abs->Book[abs->length-1].ISBN<<","<<abs->Book[abs->length-1].name<<","<<abs->Book[abs->length-1].author<<","<<abs->Book[abs->length-1].press<<","<<abs->Book[abs->length-1].price<<","<<abs->Book[abs->length-1].sum<<"\n";
	fp.close();
    fb.close();
    system("C:\\BOOK\\BOOK.txt");
    cout<<"录入成功"<<endl;
    cout<<"是否继续 1继续 0结束"<<endl;
	a = _getch();
	}while(a-48==1);
}

void removeBook(ArrayBooks *abs)
{
	int a,f=0;
	do{
	system("cls");
	char sname[100];
	cout<<"请输入需要删除的图书名称"<<endl;	
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
	fb<<"ISBN,书名,作者,出版社,价格,数量\n";
	for(int i=0;i<abs->length;i++){
		fb<<abs->Book[i].ISBN<<","<<abs->Book[i].name<<","<<abs->Book[i].author<<","<<abs->Book[i].press<<","<<abs->Book[i].price<<","<<abs->Book[i].sum<<"\n";
	}
	fb.close();
	sprintf(str,"C:\\BOOK\\%s.txt",sname);
	char *path = str;
	if(remove(path) == 0){	
		cout<<"删除成功"<<endl;
	} 
	else {
		cout<<"删除失败"<<endl; 
	}
	system("C:\\BOOK\\BOOK.txt"); 
    cout<<"是否继续 1继续 0结束"<<endl;
	a = _getch(); 
	}while(a-48==1);
}

void renewBook(ArrayBooks *abs)
{
	int a,f=0;
	do{
		system("cls");
		cout<<"输入要更改的图书的ISBN码或名称"<<endl; 
		char s[100];
		do{
		cin>>s;
		for(int i=0;i<abs->length;i++){
			if(strcmp(abs->Book[i].ISBN,s)==0 || strcmp(abs->Book[i].name,s)==0){
				f = 1;
				cout<<"需要更改的信息:"<<endl;
				cin>>s;
				cout<<"请输入更改后的信息（ISBN,书名,作者,出版社,价格,数量）";
				if(strcmp("书名",s)==0){
					cout<<"请输入更改后的书名:"<<endl; 
					cin>>abs->Book[i].name;
				}
				else if(strcmp("ISBN",s)==0){
					cout<<"请输入更改后的ISBN码:"<<endl; 
					cin>>abs->Book[i].ISBN;
				}
				else if(strcmp("出版社",s)==0){
					cout<<"请输入更改后的出版社:"<<endl; 
					cin>>abs->Book[i].press;
				}
				else if(strcmp("作者",s)==0){
					cout<<"请输入更改后的作者:"<<endl; 
					cin>>abs->Book[i].author;
				}
				else if(strcmp("价格",s)==0){
					cout<<"请输入更改后的价格:"<<endl; 
					cin>>abs->Book[i].price; 
				}
				else{
					cout<<"请输入更改后的数量:"<<endl; 
					cin>>abs->Book[i].sum;
				}
			}
		} 
		if(f==0)cout<<"未找到或输入有误,请重新输入"<<endl; 
		}while(f == 0);
		fstream fb("C:\\BOOK\\BOOK.txt",ios::out);
		fb<<"ISBN,书名,作者,出版社,价格,数量\n";
		for(int i=0;i<abs->length;i++){
			fb<<abs->Book[i].ISBN<<","<<abs->Book[i].name<<","<<abs->Book[i].author<<","<<abs->Book[i].press<<","<<abs->Book[i].price<<","<<abs->Book[i].sum<<"\n";
		}
		fb.close();
		cout<<"是否继续 1继续 0结束"<<endl;
		a = _getch();
	}while(a-48==1);
}

void showBook(ArrayBooks *abs)
{	
	int a;
	system("cls");
	if(abs->length>0){
	for(int i=0;i<abs->length;i++){
			cout<<"ISBN码: "<< abs->Book[i].ISBN <<"书名:  "<< abs->Book[i].name<<"作者:  "<< abs->Book[i].author<< "出版社:  "<< abs->Book[i].press<<"价格:  "<< abs->Book[i].price<<"数量:  "<< abs->Book[i].sum<<"\n";	
	}
	}
	else cout<<"现在还没有书"<<endl; 
	cout<<"确定"<<endl;
	a = _getch();
}
// 
void queryBook(ArrayBooks *abs)
{
	int a,f=0;
	do{
	system("cls");
	cout<<"输入要查找的图书的ISBN码或名称"<<endl; 
	char s[100];
	do{
	cin>>s;
	for(int i=0;i<abs->length;i++){
		if(strcmp(abs->Book[i].ISBN,s)==0 || strcmp(abs->Book[i].name,s)==0){
			f=1;
			cout<<"ISBN码: "<< abs->Book[i].ISBN <<"\n"<<"书名:  "<< abs->Book[i].name<<"\n"<<"作者:  "<< abs->Book[i].author<<"\n"<<"出版社:  "<< abs->Book[i].press<<"\n"<<"价格:  "<< abs->Book[i].price<<"\n"<<"数量:  "<< abs->Book[i].sum<<"\n";
		}
	}
	if(f==0)cout<<"未找到或输入有误,请重新输入"<<endl; 
	}while(f == 0);
	cout<<"是否继续 1继续 0结束"<<endl;
	a = _getch();
	}while(a-48==1);
}
                   
void end()
{
	system("cls");
	cout<<"是否删除所有图书信息"; 
	system("del C:\\BOOK");
    exit(0);
}

void menu()
{
	cout<<endl; 
	cout<<"  ■■■■■■■■■■■■■■■■■■■■  "<<endl;
	cout<<"  ■   \t\t\t\t        ■"<<endl;
    cout<<"  ■\t      "<<"图书管理系统"<<"\t        ■"<<endl;
    cout<<"  ■   \t\t\t\t        ■"<<endl;
    cout<<"  ■   \t\t\t\t        ■"<<endl;
    cout<<"  ■\t       "<<"1 增加图书 "<<"\t        ■"<<endl;
    cout<<"  ■   \t\t\t\t        ■"<<endl;
    cout<<"  ■\t       "<<"2 删除图书 "<<"\t        ■"<<endl;
    cout<<"  ■   \t\t\t\t        ■"<<endl; 
    cout<<"  ■\t       "<<"3 更新图书 "<<"\t        ■"<<endl;
    cout<<"  ■   \t\t\t\t        ■"<<endl;
    cout<<"  ■\t       "<<"4 图书库存 "<<"\t        ■"<<endl;
    cout<<"  ■   \t\t\t\t        ■"<<endl;
    cout<<"  ■\t       "<<"5 查询图书 "<<"\t        ■"<<endl;
    cout<<"  ■   \t\t\t\t        ■"<<endl;
    cout<<"  ■         "<<"你要执行的操作(1-5)"<<"        ■"<<endl;
    cout<<"  ■   \t     （ 0退出系统 ) \t        ■"<<endl;
    cout<<"  ■   \t\t\t\t        ■"<<endl;
    cout<<"  ■■■■■■■■■■■■■■■■■■■■";
}
/* 

001
《三国演义》 
罗贯中 
人民出版社
19
1 

002
《水浒传》
施耐庵
人民出版社
19
1

003
《西游记》
吴承恩
人民出版社
19
1

004
《红楼梦》
曹雪芹
人民出版社
19
1 
*/
