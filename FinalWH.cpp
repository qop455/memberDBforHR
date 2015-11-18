#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
//-----------------------------------------------------------------------------------------------------Person
class Person{										
	friend ostream& operator<<(ostream&,Person);
	friend istream& operator>>(istream&,Person&);
	protected:
		string	ID;							
		string	name;						
		int		age;						
		string	phone1;						//電話 n 代表沒有電話 輸入 n 方便用來顯示 
		string	phone2;	
		string	phone3;
		int		FLP;						//1=true 0=false
	public:
		Person(string="",string="",int=0,string="n",string="n",string="n",int=0);
		~Person();
		
		void	setID(string);
		string	getID();
		void	setname(string);
		string	getname();
		void	setage(int);
		int		getage();
		void	setphone1(string);
		string	getphone1();
		void	setphone2(string);
		string	getphone2();
		void	setphone3(string);
		string	getphone3();
		void	setFLP(int);
		int		getFLP();
		
		bool	operator==(Person);						// PERSON和PERSON做比較 , 員工及公司與WORKSFOR比較在CLASS WORKSFOR 
		void	display();
}; 
istream& operator>>(istream& in,Person& a){
	in>>a.ID>>a.name>>a.age>>a.phone1>>a.phone2>>a.phone3>>a.FLP;
	return in;
}
ostream& operator<<(ostream& out,Person a){
	out<<setw(3)<<a.ID<<setw(7)<<a.name<<setw(4)<<a.age<<setw(7)<<a.phone1<<setw(7)<<a.phone2<<setw(7)<<a.phone3<<setw(4)<<a.FLP<<endl;
	return out;
}
Person::Person(string toID,string toname,int toage,string tophone1,string tophone2,string tophone3,int toFLP){
	ID=toID;
	name=toname;
	age=toage;
	phone1=tophone1;
	phone2=tophone2;
	phone3=tophone3;
	FLP=toFLP;
}
Person::~Person(){
	ID="";
	name="";
	age=0;
	phone1="n";
	phone2="n";
	phone3="n";
	FLP=0;
}
void Person::display(){
	cout<<"ID:"<<ID<<endl;
	cout<<"Name:"<<name<<endl;
	cout<<"Age:"<<age<<endl;
	if(phone1!="n"){
		cout<<"Phone(1):"<<phone1<<endl;
	}
	if(phone2!="n"){
		cout<<"Phone(2):"<<phone2<<endl;
	}
	if(phone3!="n"){
		cout<<"Phone(3):"<<phone3<<endl;
	}
	if(FLP==1){
		cout<<name<<" is a legal person."<<endl;
	}
	else{
		cout<<name<<" isn't a legal person."<<endl;
	}
}
bool Person::operator==(Person p){
	bool result;
	if(ID==p.ID){
		result=true;
	}
	else{
		result=false;
	}
	return result;
}
void Person::setID(string toID){
	ID=toID;
}
string Person::getID(){
	return ID;
}
void Person::setname(string toname){
	name=toname;
}
string Person::getname(){
	return name;
}
void Person::setage(int toage){
	age=toage;
}
int Person::getage(){
	return age;
}
void Person::setphone1(string tophone1){
	phone1=tophone1;
}
string Person::getphone1(){
	return phone1;
}
void Person::setphone2(string tophone2){
	phone2=tophone2;
}
string Person::getphone2(){
	return phone2;                                                                            
}
void Person::setphone3(string tophone3){
	phone3=tophone3;
}
string Person::getphone3(){
	return phone3;
}
void Person::setFLP(int toFLP){
	FLP=toFLP;
}
int Person::getFLP(){
	return FLP;
}
//-----------------------------------------------------------------------------------------------------Professional
class Professional:public Person{
	friend ostream& operator<<(ostream&,Professional);
	friend istream& operator>>(istream&,Professional&);
	protected:
		string	degree;												//檔案內教育程度 P:代表碩/博士 U:代表大學  S:代表高中 J:代表國中  E:代表國小 
		string	workExperience;										//檔案內工作經驗 IT:代表資訊產業 FI:代表金融產業 ED:代表教育 ME:代表醫學醫療 SE:代表科學 
		 
	public:
		~Professional(){
			ID="";
			name="";
			age=0;
			phone1="n";
			phone2="n";
			phone3="n";
			FLP=0;
			degree="";
			workExperience="";
		}
		Professional(string="",string="",int=0,string="n",string="n",string="n",int=0,string="",string="");

		void	setdegree(string);
		string	getdegree();
		void	setworkExperience(string);
		string	getworkExperience();
		
		void	display();
};
Professional::Professional(string toID,string toname,int toage,string tophone1,string tophone2,string tophone3,int toFLP,string todegree,string toworkExperience):Person(toID,toname,toage,tophone1,tophone2,tophone3,toFLP){
	degree=todegree;
	workExperience=toworkExperience;
}
void Professional::setdegree(string todegree){
	degree=todegree;
}
string Professional::getdegree(){
	return degree;
}
void Professional::setworkExperience(string toworkExperience){
	workExperience=toworkExperience;
}
string Professional::getworkExperience(){
	return workExperience;
}
void Professional::display(){
	Person::display();
	cout<<"Degree:"<<degree<<endl;
	cout<<"Work experience:"<<workExperience<<endl;
}
ostream& operator<<(ostream& out,Professional a){
	out<<setw(3)<<a.ID<<setw(7)<<a.name<<setw(4)<<a.age<<setw(7)<<a.phone1<<setw(7)<<a.phone2<<setw(7)<<a.phone3<<setw(4)<<a.FLP<<setw(4)<<a.degree<<setw(3)<<a.workExperience<<endl;
	return out;
}
istream& operator>>(istream& in,Professional& a){
	in>>a.ID>>a.name>>a.age>>a.phone1>>a.phone2>>a.phone3>>a.FLP>>a.degree>>a.workExperience;
	return in;
}
//-----------------------------------------------------------------------------------------------------Company
class Company:public Person{
	friend ostream& operator<<(ostream&,Company);
	friend istream& operator>>(istream&,Company&);
	protected:
		string	industry;															//同 WORKEXPERIENCE 的各種產業英文代號 
		int		capital;															 
	public:
		~Company(){
			ID="";
			name="";
			age=0;
			phone1="n";
			phone2="n";
			phone3="n";
			FLP=1;
			industry="";
			capital=0;
		}
		Company(string="",string="",int=0,string="n",string="n",string="n",int=1,string="",int=0);

		void	setindustry(string);
		string	getindustry();
		void	setcapital(int);
		int		getcapital();
		
		void	display();
};
Company::Company(string toID,string toname,int toage,string tophone1,string tophone2,string tophone3,int toFLP,string toindustry,int tocapital):Person(toID,toname,toage,tophone1,tophone2,tophone3,toFLP){
	industry=toindustry;
	capital=tocapital;
}
void Company::setindustry(string toindustry){
	industry=toindustry;
}
string Company::getindustry(){
	return industry;
}
void Company::setcapital(int tocapital){
	capital=tocapital;
}
int Company::getcapital(){
	return capital;
}
void Company::display(){
	Person::display();
	cout<<"Industry:"<<industry<<endl;
	cout<<"Capital:"<<capital<<endl;
}
ostream& operator<<(ostream& out,Company a){
	out<<setw(4)<<a.ID<<setw(6)<<a.name<<setw(4)<<a.age<<setw(7)<<a.phone1<<setw(7)<<a.phone2<<setw(7)<<a.phone3<<setw(4)<<a.FLP<<setw(4)<<a.industry<<setw(10)<<a.capital<<endl;
	return out;
}
istream& operator>>(istream& in,Company& a){
	in>>a.ID>>a.name>>a.age>>a.phone1>>a.phone2>>a.phone3>>a.FLP>>a.industry>>a.capital;
	return in;
}
//-----------------------------------------------------------------------------------------------------Worksfor
class Worksfor{
	friend ostream& operator<<(ostream&,Worksfor);
	friend istream& operator>>(istream&,Worksfor&);
	protected:
		string PID;
		string CID;
		int year;																	//代表在公司工作了幾年 
		int salary;																	
	public:
		Worksfor(string="",string="",int=0,int=0);

		void setPID(string);
		string getPID();
		void setCID(string);
		string getCID();
		void setyear(int);
		int getyear();
		void setsalary(int);
		int getsalary();
		
		bool operator==(Professional);  
		bool operator==(Company);
		
		void display();
};
Worksfor::Worksfor(string toPID,string toCID,int toyear,int tosalary){
	PID=toPID;
	CID=toCID;
	year=toyear;
	salary=tosalary;
}
void Worksfor::setPID(string toPID){
	PID=toPID;
}
string Worksfor::getPID(){
	return PID;
}
void Worksfor::setCID(string toCID){
	CID=toCID;
}
string Worksfor::getCID(){
	return CID;
}
void Worksfor::setyear(int toyear){
	year=toyear;
}
int Worksfor::getyear(){
	return year;
}
void Worksfor::setsalary(int tosalary){
	salary=tosalary;
}
void Worksfor::display(){
	cout<<"Company'ID:"<<CID<<endl;
	cout<<"Work years:"<<year<<endl;
	cout<<"Salary:"<<salary<<endl;
}
int Worksfor::getsalary(){
	return salary;
}
ostream& operator<<(ostream& out,Worksfor a){
	out<<setw(4)<<a.PID<<setw(4)<<a.CID<<setw(5)<<a.year<<setw(7)<<a.salary<<endl;
	return out;
}
istream& operator>>(istream& in,Worksfor& a){
	in>>a.PID>>a.CID>>a.year>>a.salary;
	return in;
}
bool Worksfor::operator==(Professional p){
	bool result;
	if(PID==p.getID()){
		result=true;
	}
	else{
		result=false;
	}
	return result;
}
bool Worksfor::operator==(Company C){
	bool result;
	if(CID==C.getID()){
		result=true;
	}
	else{
		result=false;
	}
	return result;
}
//-----------------------------------------------------------------------------------------------------dbHR
const int maxsize=100;

class dbHR{
	protected:
		int psize;
		int wsize;
		int csize;
		Professional p[maxsize];
		Worksfor w[maxsize];
		Company c[maxsize];
	public:
		dbHR(){
			psize=0;
			wsize=0;
			csize=0;
		};
		~dbHR(){
			psize=0;
			wsize=0;
			csize=0;
		};
		int getpsize();
		int getwsize();
		int getcsize();
		
		void readfromfile();
		void savetofile();
		
		void searchPnumthroughC();
		void countaverageAandSineachIN();
		void searchCthroughP();
		void countPineachC();
		void searchCthroughWE();
		void searchPthroughC();
		void revicedata();
		
		void dbHRdisplay();
		
		void addp();
		void addc();
}; 
void dbHR::readfromfile(){
	ifstream infile;
	infile.open("Professional.txt");
	while(infile>>p[psize]){
		psize++;
	}
	infile.close();
	
	infile.open("Company.txt");
	while(infile>>c[csize]){
		csize++;
	}
	infile.close();
	
	infile.open("Worksfor.txt");
	while(infile>>w[wsize]){
		wsize++;
	}
	infile.close();
}
void dbHR::savetofile(){
	ofstream outfile;
	outfile.open("Professional.txt");
	for(int pi=0;pi<psize;pi++){
		outfile<<p[pi];
	}
	outfile.close();
	
	outfile.open("Company.txt");
	for(int ci=0;ci<csize;ci++){
		outfile<<c[ci];
	}
	outfile.close();
	
	outfile.open("Worksfor.txt");
	for(int wi=0;wi<wsize;wi++){
		outfile<<w[wi];
	}
	outfile.close();
}
int dbHR::getpsize(){
	return psize;
}
int dbHR::getwsize(){
	return wsize;
}
int dbHR::getcsize(){
	return csize;
}
//1
void dbHR::dbHRdisplay(){
	cout<<"-----------------All Professionals ("<<psize<<")-----------------"<<endl;
	cout<<setw(5)<<" "<<setw(3)<<"ID"<<setw(7)<<"name"<<setw(4)<<"age"<<setw(7)<<"phone1"<<setw(7)<<"phone2"<<setw(7)<<"phone3"<<setw(4)<<"FLP"<<setw(4)<<"DEG"<<setw(3)<<"WE"<<endl;
	for(int i=0;i<psize;i++){
		cout<<setw(2)<<"P("<<setw(2)<<i+1<<")"<<p[i];
	}
	cout<<"-----------------All Worksfors ("<<wsize<<")-----------------"<<endl;
	cout<<setw(5)<<" "<<setw(4)<<"PID"<<setw(4)<<"CID"<<setw(5)<<"year"<<setw(7)<<"salary"<<endl;
	for(int i=0;i<wsize;i++){
		cout<<setw(2)<<"W("<<setw(2)<<i+1<<")"<<w[i];
	}
	cout<<"-----------------All Companys ("<<csize<<")-----------------"<<endl;
	cout<<setw(5)<<" "<<setw(4)<<"ID"<<setw(6)<<"name"<<setw(4)<<"age"<<setw(7)<<"phone1"<<setw(7)<<"phone2"<<setw(7)<<"phone3"<<setw(4)<<"FLP"<<setw(4)<<"IN"<<setw(10)<<"capital"<<endl;
	for(int i=0;i<csize;i++){
		cout<<setw(2)<<"C("<<setw(2)<<i+1<<")"<<c[i];
	}
}
//2
void dbHR::addp(){
	Professional a;
	cout<<"-----------------Add a new Professional-----------------"<<endl;
	
	string tempID;
	int checkID=0;
	cout<<"Enter his/her ID (EX:01,02...):";
	cin>>tempID;
	for(int pi=0;pi<psize;pi++){
		if(p[pi].getID()==tempID){
			checkID=1;
		}
	}
	while(checkID==1){
		checkID=0;
		cout<<"ID '"<<tempID<<"' is exist.Please enter his/her ID again ";
		if(psize+1>9){
			cout<<"(EX:"<<psize+1<<"...):";
		}
		else{
			cout<<"(EX:0"<<psize+1<<"...):";
		}
		cin>>tempID;
		for(int pi=0;pi<psize;pi++){
			if(p[pi].getID()==tempID){
				checkID=1;
			}
		}
	}
	a.setID(tempID);
	
	string tempname;
	cout<<"Enter his/her name:";
	cin>>tempname;
	a.setname(tempname);
	
	int tempage;
	cout<<"Enter his/her age:";
	cin>>tempage;
	a.setage(tempage);
	
	string tempphone1;
	cout<<"Enter his/her phone(1),(If no phonenumber,please enter 'n' to skip):";
	cin>>tempphone1;
	a.setphone1(tempphone1);
	if(tempphone1!="n"){
		string tempphone2;
		cout<<"Enter his/her phone(2),(If no more phonenumber,please enter 'n' to skip):";
		cin>>tempphone2;
		a.setphone2(tempphone2);
		if(tempphone2!="n"){
			string tempphone3;
			cout<<"Enter his/her phone(3),(If no more phonenumber,please enter 'n' to skip):";
			cin>>tempphone3;
			a.setphone3(tempphone3);
		}
		else{
			a.setphone3("n");
		}
	}
	
	cout<<"A Professional is not a legal person!"<<endl;
	a.setFLP(0);
	
	string tempdegree;
	cout<<"Enter his/her degree (EX:P:碩/博士 U:大學  S:高中 J:國中  E:國小):";
	cin>>tempdegree;
	a.setdegree(tempdegree);
	
	string tempworkExperience;
	cout<<"Enter his/her workExperience (EX:IT:資訊產業 FI:金融產業 ED:教育 ME:醫學醫療 SE:科學):";
	cin>>tempworkExperience;
	while(tempworkExperience!="IT"&&tempworkExperience!="FI"&&tempworkExperience!="ED"&&tempworkExperience!="ME"&&tempworkExperience!="SE"){
		cout<<"His/Her workExperiencee '"<<tempworkExperience<<"' is not exist.Please enter again."<<endl;
		cout<<"Enter his/her workExperience (EX:IT:資訊產業 FI:金融產業 ED:教育 ME:醫學醫療 SE:科學):";
		cin>>tempworkExperience;
	}
	a.setworkExperience(tempworkExperience);
	
	Worksfor b;
	
	b.setPID(a.getID());
	
	string tempCID;
	cout<<"Enter his/her company's ID(EX:AAA,BBB...):";
	cin>>tempCID;
	
	int check=0;
	for(int ci=0;ci<csize;ci++){
		if(c[ci].getID()==tempCID){
			check=1;
		}
	}
	if(check==0){
		cout<<"Company's ID isn't exist.Please add a new Company's information with ID '"<<tempCID<<"' after adding this Professional."<<endl;
	}
	b.setCID(tempCID);
	
	int tempyear;
	cout<<"Enter years he/she has worked in this Company:";
	cin>>tempyear;
	b.setyear(tempyear);
	
	int tempsalary;
	cout<<"Enter his/her salary:";
	cin>>tempsalary;
	b.setsalary(tempsalary);
	
	p[psize]=a;
	w[wsize]=b;
	psize++;
	wsize++;
	
	if(check==0){
		cout<<"--------Please add a new Company with ID '"<<tempCID<<"'.--------"<<endl;
		addc();
	}	
} 
//3
void dbHR::addc(){
	Company a;
	cout<<"-----------------Add a new Company-----------------:"<<endl;
	int checkID=0;
	string tempID;
	cout<<"Enter Company's ID (EX:AAA,BBB...):";
	cin>>tempID;
	for(int ci=0;ci<csize;ci++){
		if(c[ci].getID()==tempID){
			checkID=1;
		}
	}
	while(checkID==1){
		checkID=0;
		cout<<"ID '"<<tempID<<"' is exist.Please enter Company's ID again(EX:FFF,GGG...):";
		cin>>tempID;
		for(int ci=0;ci<csize;ci++){
			if(c[ci].getID()==tempID){
				checkID=1;
			}
		}
	}
	a.setID(tempID);
	
	string tempname;
	cout<<"Enter Company's name:";
	cin>>tempname;
	a.setname(tempname);
	
	int tempage;
	cout<<"Enter Company's age:";
	cin>>tempage;
	a.setage(tempage);
	
	string tempphone1;
	cout<<"Enter Company's phone(1),(If no phonenumber,please enter 'n' to skip):";
	cin>>tempphone1;
	a.setphone1(tempphone1);
	if(tempphone1!="n"){
		string tempphone2;
		cout<<"Enter Company's phone(2),(If no more phonenumber,please enter 'n' to skip):";
		cin>>tempphone2;
		a.setphone2(tempphone2);
		if(tempphone2!="n"){
			string tempphone3;
			cout<<"Enter Company's phone(3),(If no more phonenumber,please enter 'n' to skip):";
			cin>>tempphone3;
			a.setphone3(tempphone3);
		}
		else{
			a.setphone3("n");
		}
	}
	
	cout<<"A company is a legal person.";
	cout<<endl;
	a.setFLP(1);
	
	string tempindustry;
	cout<<"Enter Company's industry (EX:IT:資訊產業 FI:金融產業 ED:教育 ME:醫學醫療 SE:科學):";
	cin>>tempindustry;
	while(tempindustry!="IT"&&tempindustry!="FI"&&tempindustry!="ED"&&tempindustry!="ME"&&tempindustry!="SE"){
		cout<<"Industry '"<<tempindustry<<"' is not exist.Please enter again."<<endl;
		cout<<"Enter Company's industry (EX:IT:資訊產業 FI:金融產業 ED:教育 ME:醫學醫療 SE:科學):";
		cin>>tempindustry;
	}
	a.setindustry(tempindustry);
	
	int tempcapital;
	cout<<"Enter Company's capital:";
	cin>>tempcapital;
	a.setcapital(tempcapital);
	
	c[csize]=a;
	csize++;
}
//4
void dbHR::searchPnumthroughC(){
	string search;
	int num=0;
	cout<<"Enter an Company's ID/name to search(EX:AAA,BBB...):";
	int check=0;
	cin>>search;
	for(int ci=0;ci<csize;ci++){
		if(c[ci].getID()==search||c[ci].getname()==search){
			for(int wi=0;wi<psize;wi++){
				if(w[wi].getCID()==c[ci].getID()){
					if(num<1){
						cout<<"------------porfessionals working in Company '"<<search<<"'------------"<<endl;
					}
					cout<<endl;
					p[wi].display();
					num++;
				}
			}
			check=1;
		}
	}
	while(check==0){
		cout<<"Company's ID/name '"<<search<<"' is not exist.Please enter an Company's ID/name again(EX:AAA,BBB...):";
		cin>>search;
		for(int ci=0;ci<csize;ci++){
			if(c[ci].getID()==search||c[ci].getname()==search){
				for(int wi=0;wi<psize;wi++){
					if(w[wi]==c[ci]){
						if(num<1){
							cout<<"------------porfessionals working in Company '"<<search<<"'------------"<<endl;
						}
						cout<<endl;
						p[wi].display();
						num++;
					}
				}
				check=1;
			}
		}
	}
	cout<<endl;
	cout<<"There are totally "<<num<<" people working in Company '"<<search<<"'."<<endl;
}
//5
void dbHR::countaverageAandSineachIN(){
	const int imax=5;
	string industry[imax]={"IT","FI","ED","ME","SE"};
	int averageAge[imax]={0};
	int averageSalary[imax]={0};
	int people[imax]={0};
	
	cout<<"Count each Insdustry's Professionals' average age and salary!!";
	cout<<endl;
	for(int i=0;i<imax;i++){
		for(int ci=0;ci<csize;ci++){
			if(industry[i]==c[ci].getindustry()){
				for(int wi=0;wi<wsize;wi++){
					if(w[wi]==c[ci]){
						averageAge[i]+=p[wi].getage();
						averageSalary[i]+=w[wi].getsalary();
						people[i]++;
					}
				}
			}
		}
	}
	for(int ii=0;ii<imax-1;ii++){
		for(int jj=0;jj<imax-ii-1;jj++){
			if(averageSalary[jj]<averageSalary[jj+1]){
				int changeSalary=averageSalary[jj];
				averageSalary[jj]=averageSalary[jj+1];
				averageSalary[jj+1]=changeSalary;
				int changeAge=averageAge[jj];
				averageAge[jj]=averageAge[jj+1];
				averageAge[jj+1]=changeAge;
				int changepeople=people[jj];
				people[jj]=people[jj+1];
				people[jj+1]=changepeople;
				string changeIN=industry[jj];
				industry[jj]=industry[jj+1];
				industry[jj+1]=changeIN;
			}
		}
	}
	cout<<"各INDUSTRY 以salary大到小排列顯示:"<<endl;
	for(int i=0;i<imax;i++){
		if(people[i]!=0){
			cout<<"Industry '"<<industry[i]<<"'s ' avarage salary is :"<<(double)averageSalary[i]/people[i]<<" & average age is "<<(double)averageAge[i]/people[i]<<"."<<endl;
		}
		else{
			cout<<"Industry '"<<industry[i]<<"' has no professional."<<endl;
		}
	} 
}
//6
void dbHR::searchCthroughP(){
	string search;
	cout<<"Enter a Professional's ID/name to search his/her company (EX:01,Jason...):";
	cin>>search;
	int check=0;
	for(int pi=0;pi<psize;pi++){
		if(search==p[pi].getID()||search==p[pi].getname()){
			for(int ci=0;ci<csize;ci++){
				if(w[pi]==c[ci]){
					cout<<"--------"<<p[pi].getname()<<"'s company's imformation is as below--------"<<endl;
					c[ci].display();
				}
			}
			check=1;     
		}
	}
	while(check==0){            
		cout<<"Professional's ID/name '"<<search<<"' is not exist.Please enter a Professional's ID/name again (EX:01,Jason...):";
		cin>>search;
		for(int pi=0;pi<psize;pi++){
			if(search==p[pi].getID()||search==p[pi].getname()){
				for(int ci=0;ci<csize;ci++){
					if(w[pi]==c[ci]){
						cout<<"--------"<<p[pi].getname()<<"'s company's imformation is as below--------"<<endl;
						c[ci].display();
					}
				}
				check=1;     
			}
		}
	}
}
//7
void dbHR::countPineachC(){
	cout<<"--------Count Professionals in each Company!--------"<<endl;
	int num[100]={0};
	for(int ci=0;ci<csize;ci++){
		for(int wi=0;wi<wsize;wi++){
			if(w[wi]==c[ci]){
				num[ci]++;
			}
		}
	}
	for(int i=0;i<csize;i++){
		cout<<"Company '"<<c[i].getname()<<"' has "<<num[i]<<" Professionals."<<endl;
	}
}
//8
void dbHR::searchCthroughWE(){
	string search;
	int check=0;
	cout<<"Enter a Professional's ID/name and then use his/her work experience to find Company with the same industry (EX:01,Jason...):";
	cin>>search;
	for(int pi=0;pi<psize;pi++){
		if(p[pi].getID()==search||p[pi].getname()==search){
			cout<<p[pi].getname()<<"'s work experience is "<<p[pi].getworkExperience()<<" ."<<endl;
			cout<<"Compnays with the same industy are as below:"<<endl;
			for(int ci=0;ci<csize;ci++){
				if(p[pi].getworkExperience()==c[ci].getindustry()){
					c[ci].display();
					cout<<endl;
				}
			}
			check=1;
		}
	}
	while(check==0){
		cout<<"There is no Professional's ID/name '"<<search<<"'.Please enter again."<<endl;
		cout<<"Enter a Professional's ID/name and then use his/her work experience to find Company with the same industry(EX:01,Jason...):";
		cin>>search;
		for(int pi=0;pi<psize;pi++){
			if(p[pi].getID()==search||p[pi].getname()==search){
				cout<<p[pi].getname()<<"'s work experience is "<<p[pi].getworkExperience()<<" ."<<endl;
				cout<<"Compnays with the same industy are as below:"<<endl;
				for(int ci=0;ci<csize;ci++){
					if(p[pi].getworkExperience()==c[ci].getindustry()){
						c[ci].display();
						cout<<endl;
					}
				}
				check=1;
			}
		}
	}
}
//9
void dbHR::searchPthroughC(){
	string maxID;
	string minID;
	int maxyear=0;
	int minyear=99;
	cout<<"--------Search all companys and display their Professional who works in this company earliest--------"<<endl;
	for(int ci=0;ci<csize;ci++){
		for(int wi=0;wi<psize;wi++){
			if(w[wi]==c[ci]){
				if(maxyear<=w[wi].getyear()){
					maxyear=w[wi].getyear();
					maxID=p[wi].getID();
				}
				if(minyear>=w[wi].getyear()){
					minyear=w[wi].getyear();
					minID=p[wi].getID();
				}
			}
		}
		cout<<"----Company ' "<<c[ci].getname()<<"'s ' Professional who works in this company earliest----"<<endl;
		for(int i=0;i<psize;i++){
			if(maxID==p[i].getID()){
				p[i].display();
				cout<<"He/She has worked for "<<w[i].getyear()<<" year(s)."<<endl;
			}
		}
		cout<<"----And one who works in this company latest----"<<endl;
		for(int i=0;i<psize;i++){
			if(minID==p[i].getID()){
				p[i].display();
				cout<<"He/She has worked for "<<w[i].getyear()<<" year(s)."<<endl;
				cout<<endl;
			}
		}
		cout<<endl;
		maxyear=0;
		minyear=99;
	}
}
//10
void dbHR::revicedata(){
	cout<<"---------------Choose a function to work---------------";
	cout<<"(1).Revice a Professional or Worksfor data (2).Revice a Company data:";
	int chooseF=0;
	int chooseD=0;
	string search;
	int checkP=0;
	int checkC=0;
	
	cin>>chooseF;
	while(chooseF!=1&&chooseF!=2){
		cout<<"No function!Please choose again:";
		cin>>chooseF;
	}
	if(chooseF==1){
		cout<<"Enter a Professional's ID to revice(EX:01,02...):";
		cin>>search;
		while(checkP==0){
			for(int pi=0;pi<psize;pi++){
				 if(p[pi].getID()==search){
				 	checkP=1;
					cout<<"---------------Before revice---------------"<<endl;
					p[pi].display();
					w[pi].display();
					cout<<"---------------Choose a data to revice---------------"<<endl;
					cout<<"(1).Name (2).Age (3).Phone (4).Degree (5).Work Experience (6).His/Her company's ID (7).Work years (8).Salary : ";
					cin>>chooseD;
					while(chooseD>8||chooseD<1){
						cout<<"Data is not exist.Please choose again:";
						cin>>chooseD;
					}
					if(chooseD==1){
						string rename;
						cout<<"Please enter a new name:";
						cin>>rename;
						p[pi].setname(rename);
						cout<<"---------------After revice 'name'---------------"<<endl;
						p[pi].display();
						w[pi].display();
					}
					else if(chooseD==2){
						int reage;
						cout<<"Please enter a new age:";
						cin>>reage;
						p[pi].setage(reage);
						cout<<"---------------After revicie 'age'---------------"<<endl;
						p[pi].display();
						w[pi].display();
					}
					else if(chooseD==3){
						int rephone;
						int choose=0;
						while(choose<1||choose>2){
							cout<<"Enter '1'.to revice phone '2'.to add new a phone:";
							cin>>choose;
						}
						if(choose==1){
							if(p[pi].getphone1()!="n"){
								cout<<"Please enter a new phone1(or enter 'n' not to add):";
								string rephone1;
								cin>>rephone1; 
								p[pi].setphone1(rephone1);
								if(p[pi].getphone2()!="n"){
									cout<<"Please enter a new phone2(or enter 'n' not to add):";
									string rephone2;
									cin>>rephone2; 
									p[pi].setphone2(rephone2);
									if(p[pi].getphone3()!="n"){
										cout<<"Please enter a new phone(or enter 'n' not to add)3:";
										string rephone3;
										cin>>rephone3; 
										p[pi].setphone3(rephone3);
									}
								}
								cout<<"---------------After revicie 'phone'---------------"<<endl;
								p[pi].display();
								w[pi].display();
							}
							else{
								cout<<"You didn't have any phone."<<endl;
							}
						}
						else{
							if(p[pi].getphone1()=="n"){
								cout<<"Please enter a new phone1 to add(or enter 'n' not to add):";
								string newphone1;
								cin>>newphone1;
								p[pi].setphone1(newphone1);
							}
							if(p[pi].getphone2()=="n"){
								cout<<"Please enter a new phone2 to add(or enter 'n' not to add):";
								string newphone2;
								cin>>newphone2;
								p[pi].setphone2(newphone2);
							}
							if(p[pi].getphone3()=="n"){
								cout<<"Please enter a new phone3 to add(or enter 'n' not to add):";
								string newphone3;
								cin>>newphone3;
								p[pi].setphone3(newphone3);
							}
							cout<<"---------------After add 'phone'---------------"<<endl;
							p[pi].display();
							w[pi].display();
						}
					}
					else if(chooseD==4){
						string redegree;
						cout<<"Please enter a new degree (EX:P:碩/博士 U:大學  S:高中 J:國中  E:國小):";
						cin>>redegree;
						p[pi].setdegree(redegree);
						cout<<"---------------After revice 'degree'---------------"<<endl;
						p[pi].display();
						w[pi].display();
					}
					else if(chooseD==5){
						string reWE;
						cout<<"Please enter a new work experience (EX:IT:資訊產業 FI:金融產業 ED:教育 ME:醫學醫療 SE:科學):";
						cin>>reWE;
						while(reWE!="IT"&&reWE!="FI"&&reWE!="ED"&&reWE!="ME"&&reWE!="SE"){
							cout<<"His/Her workExperiencee '"<<reWE<<"' is not exist.Please enter again."<<endl;
							cout<<"Enter his/her workExperience (EX:IT:資訊產業 FI:金融產業 ED:教育 ME:醫學醫療 SE:科學):";
							cin>>reWE;
						}
						p[pi].setworkExperience(reWE);
						cout<<"---------------After revice 'work experience'---------------"<<endl;
						p[pi].display();
						w[pi].display();
					}
					else if(chooseD==6){
						string reCID;
						cout<<"Please enter a new company's ID (EX:AAA,BBB...):";
						cin>>reCID;
						int checkCID=0;
						for(int i=0;i<csize;i++){
							if(reCID==c[i].getID()){
								checkCID=1;
							}
						}
						if(checkCID==0){
							cout<<"Company's ID isn't exist.Please add a new Company's information with ID '"<<reCID<<"'."<<endl;
							addc();
						}
						w[pi].setCID(reCID);
						cout<<"---------------After revice 'company's ID'---------------"<<endl;
						p[pi].display();
						w[pi].display();
					}
					else if(chooseD==7){
						int reyear;
						cout<<"Please enter a new work years:";
						cin>>reyear;
						w[pi].setyear(reyear);
						cout<<"---------------After revice 'work years'---------------"<<endl;
						p[pi].display();
						w[pi].display();
					}
					else if(chooseD==8){
						int resalary;
						cout<<"Please enter a new salary:";
						cin>>resalary;
						w[pi].setsalary(resalary);
						cout<<"---------------After revice 'salary'---------------"<<endl;
						p[pi].display();
						w[pi].display();
					}
					else{
						cout<<"Wrong!!!!!!!!!!!!"<<endl;
					}
				}
			}
			if(checkP==0){
				cout<<"Professional's ID '"<<search<<"' is not exist.Please enter a Professional's ID again (EX:01,02...):";
				cin>>search;
			}
		}
	}
	else{
		cout<<"Enter a Company's ID to revice (EX:AAA,BBB...):";
		cin>>search;
		while(checkC==0){
			for(int ci=0;ci<csize;ci++){
				 if(c[ci].getID()==search){
				 	checkC=1;
					cout<<"---------------Before revice---------------"<<endl;
					c[ci].display();
					cout<<"---------------Choose a data to revice---------------"<<endl;
					cout<<"(1).Name (2).Age (3).Phone (4).Industry (5).Capital :";
					cin>>chooseD;
					while(chooseD>5||chooseD<1){
						cout<<"Data is not exist.Please choose again:";
						cin>>chooseD;
					}
					if(chooseD==1){
						string rename;
						cout<<"Please enter a new name:";
						cin>>rename;
						c[ci].setname(rename);
						cout<<"---------------After revice 'name'---------------"<<endl;
						c[ci].display();
					}
					else if(chooseD==2){
						int reage;
						cout<<"Please enter a new age:";
						cin>>reage;
						c[ci].setage(reage);
						cout<<"---------------After revicie 'age'---------------"<<endl;
						c[ci].display();
					}
					else if(chooseD==3){
						int rephone;
						int choose=0;
						while(choose<1||choose>2){
							cout<<"Enter '1'.to revice phone '2'.to add new a phone:";
							cin>>choose;
						}
						if(choose==1){
							if(c[ci].getphone1()!="n"){
								cout<<"Please enter a new phone1(or enter 'n' not to add):";
								string rephone1;
								cin>>rephone1; 
								c[ci].setphone1(rephone1);
								if(c[ci].getphone2()!="n"){
									cout<<"Please enter a new phone2(or enter 'n' not to add):";
									string rephone2;
									cin>>rephone2; 
									c[ci].setphone2(rephone2);
									if(c[ci].getphone3()!="n"){
										cout<<"Please enter a new phone3(or enter 'n' not to add):";
										string rephone3;
										cin>>rephone3; 
										c[ci].setphone3(rephone3);
									}
								}
								cout<<"---------------After revicie 'phone'---------------"<<endl;
								c[ci].display();
							}
							else{
								cout<<"You didn't have any phone."<<endl;
							}
						}
						else{
							if(c[ci].getphone1()=="n"){
								cout<<"Please enter a new phone1 to add(or enter 'n' not to add):";
								string newphone1;
								cin>>newphone1;
								c[ci].setphone1(newphone1);
							}
							if(c[ci].getphone2()=="n"){
								cout<<"Please enter a new phone2 to add(or enter 'n' not to add):";
								string newphone2;
								cin>>newphone2;
								c[ci].setphone2(newphone2);
							}
							if(c[ci].getphone3()=="n"){
								cout<<"Please enter a new phone3 to add(or enter 'n' not to add):";
								string newphone3;
								cin>>newphone3;
								c[ci].setphone3(newphone3);
							}
							cout<<"---------------After add 'phone'---------------"<<endl;
							c[ci].display();
						}
					}
					else if(chooseD==4){
						string reindustry;
						cout<<"Please enter a new industry (EX:IT:資訊產業 FI:金融產業 ED:教育 ME:醫學醫療 SE:科學):";
						cin>>reindustry;
						while(reindustry!="IT"&&reindustry!="FI"&&reindustry!="ED"&&reindustry!="ME"&&reindustry!="SE"){
							cout<<"Industry '"<<reindustry<<"' is not exist.Please enter again."<<endl;
							cout<<"Enter Company's industry (EX:IT:資訊產業 FI:金融產業 ED:教育 ME:醫學醫療 SE:科學):";
							cin>>reindustry;
						}
						c[ci].setindustry(reindustry);
						cout<<"---------------After revice 'industry'---------------"<<endl;
						c[ci].display();
					}
					else if(chooseD==5){
						int recapital;
						cout<<"Please enter a new capital:";
						cin>>recapital;
						c[ci].setcapital(recapital);
						cout<<"---------------After revice 'capital'---------------"<<endl;
						c[ci].display();
					}
					else{
						cout<<"Wrong!"<<endl;
					}
				}
			}
			if(checkC==0){
				cout<<"Company's ID '"<<search<<"' is not exist.Please enter a Company's ID again(EX:AAA,BBB...):";
				cin>>search;
			}
		}
	}
}

//-----------------------------------------------------------------------------------------------------main
int main(){
	cout<<right;
	dbHR mydbHR;
	mydbHR.readfromfile();										//讀檔
	cout<<"P-size:"<<mydbHR.getpsize()<<endl;					//顯示目前儲存數量
	cout<<"W-size:"<<mydbHR.getwsize()<<endl;
	cout<<"C-size:"<<mydbHR.getcsize()<<endl; 
	
	int choose=0;														//提示使用者選擇功能 
	cout<<"----------------Choose a function to work----------------"<<endl;
	cout<<"(1).Display (2).Add Professional (3).Add Company (4).Count how many Professionals there are through Company (5).Count average age and salary in each Industry ";
	cout<<"(6).Search Company through Professional (7).Count Professionals in each Company (8)Search Company through a Professional's Work Experience (9).Search Professional through all Companys ";
	cout<<"(10).Revice data (0).Exit & save):";
	cin>>choose;
	while(choose!=0){
		if(choose==1){											//顯示出所有PROFESSIONAL COMPANY WORKSFOR 資料 
			mydbHR.dbHRdisplay();
		}
		else if(choose==2){										//新增一個PROFESSIONAL 同時新增WORKSFOR 當PROFESSIONAL 的CID 不存在時自動新增 COMPANY 並提示CID 
			mydbHR.addp();										//員工ID如果已經存在,需要重新輸入 
		}	
		else if(choose==3){										//新增一個 COMPANY
			mydbHR.addc();										//公司ID如果已經存在,需要重新輸入 
		}
		else if(choose==4){										//輸入公司ID或NAME尋找公司底下的員工並顯示員工資訊 
			mydbHR.searchPnumthroughC();						//公司ID或NAME不存在,需要重新尋找
		}
		else if(choose==5){										//計算並顯示各產業的平均年齡與薪水再依照平均薪水由大到小排列 
			mydbHR.countaverageAandSineachIN();
		}
		else if(choose==6){										//輸入員工ID或NAME尋找員工所屬公司 
			mydbHR.searchCthroughP();							//員工ID或NAME不存在,需要重新尋找
		}
		else if(choose==7){										//計算並顯示各公司底下員工數量 
			mydbHR.countPineachC();
		}
		else if(choose==8){										//輸入員工ID或NAME尋找所有產業與該員工工作經驗相符的公司 
			mydbHR.searchCthroughWE();
		}
		else if(choose==9){										//顯示各公司所雇用有最大或最小YEAR的員工資訊 
			mydbHR.searchPthroughC();
		}
		else if(choose==10){									//修改員工,公司資料 
			mydbHR.revicedata();								//員工或公司ID或NAME不存在,需要重新尋找
		}														
		else{													//輸入訊息錯誤提示 
			cout<<"No function! Please enter again!!";
			cout<<endl;
		}																//再次提示使用選擇功能 
		cout<<"----------------Choose a function to work----------------"<<endl;
		cout<<"(1).Display (2).Add Professional (3).Add Company (4).Count how many Professionals there are through Company (5).Count average age and salary in each Industry ";
		cout<<"(6).Search Company through Professional (7).Count Professionals in each Company (8)Search Company through a Professional's Work Experience (9).Search Professional through all Companys ";
		cout<<"(10).Revice data (0).Exit & save):";
		cin>>choose;
		if(cin.fail()){											//提示輸入型態錯誤並離開程式 
			cout<<"--------Wrong type!! QUIT WITHOUT SAVE!!!!!!!!!!!--------";
			return 0;
		}
	}
	if(cin.fail()){
		cout<<"--------Wrong type!! QUIT WITHOUT SAVE!!!!!!!!!!!--------";
	}
	else{
		cout<<"--------SAVE & QUIT!!!!!!!!!!!--------";
		mydbHR.savetofile();
	}
	return 0;
}
