//Driving Licence Test
//pword is agnel1234

#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<iomanip.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>

class test
{
	int Qid;
	char question[200];
	char opt[4][20];
	int answer;

public:

	int retid();
	int RetAns();
	void IN(int);
	void INe();
	void OUT();
	void OUTt(int);

}; //End of class test

class applicant
{
	long int ID;
	char name[30];
	int QA;
	char result;

public:
	applicant();
	void SetResult();
	void SetQA(int);
	void DispRes();
	char RetRes();
	long int RetID();
	char * RetName();
	void IN();
	void INe();
	void INa();
	void OUT();

}; //End of class applicant

applicant::applicant()
{
	QA=0;
	result='N';

} //End of applicant() : constructor

void applicant::IN()
{
	cout<<"\n\n\t\t    Enter Registration ID:\t";
	cin>>ID;
	cout<<"\n\n\t\t    Enter Registered (full) name:\t";
	gets(name);

} //End of IN()

void applicant::INe()
{
	cout<<"\n\n\t\t    Enter new name:\t";
	gets(name);

} //End of INe()

long int autogena();

void applicant::INa()
{
	ID=autogena();
	cout<<"\n\n\t\t    Registration ID:\t";
	cout<<ID;
	cout<<"\n\n\t\t    Enter (full) name:\t";
	gets(name);

} //End of INa()

void applicant::SetResult()
{
	if(QA>=3)
		result='P';
	else
		result='F';

} //End of SetResult()

void applicant::SetQA(int q)
{
	QA=q;

} //End of SetQA()

long int applicant::RetID()
{
	return ID;

} //End of RetID()

char * applicant::RetName()
{
	return name;

} //End of RetName()

void applicant::DispRes()
{
	cout<<"\n";
	for(int i=0; i<78; i++)
		cout<<(char)196;
	cout<<"\n\n\t\t"<<setw(20)<<"Questions attempted correctly:"<<setw(10)<<QA<<"/5";

} //End of DispRes()

char applicant::RetRes()
{
	return result;

} //End of RetRes()

void applicant::OUT()
{

	cout<<setw(5)<<ID<<"."<<setw(25)<<name<<setw(25)<<QA;

	if(result=='P')
	{
		cout<<setw(20)<<"Pass";
	}
	else if(result=='F')
	{
		cout<<setw(20)<<"Fail";
	}
	else if(result=='N')
		cout<<setw(20)<<"Not Tested";

} //End of OUT()

int CHECK(int n)
{
	if(n<1||n>4)
	{
		cout<<"\n\t\tOption number must lie in the range 1-4";
		return 1;
	}
	else
		return 0;

} //End of CHECK()

int test::retid()
{
	return Qid;
}
//End of retid()

int test::RetAns()
{
	return answer;

} //End of RetAns()

void test::IN(int id)
{
	Qid=id;
	cout<<"\nQuestion ID: "<<Qid;
	cout<<"\n\nEnter text: \n";
	gets(question);

	cout<<"\nEnter options: \n";

	for(int i=0; i<4; i++)
	{
		cout<<"\n\t\t\t("<<i+1<<")\t";
		gets(opt[i]);
	}

	c:

	cout<<"\n\n\t\tEnter the answer (correct option number):\t";
	cin>>answer;

	if(CHECK(answer))
	{
		gotoxy(0,15);
		clreol;
		goto c;
	}

} //End of IN()

void test::INe()
{
	char choice;
	int optn;

	do
	{
		cout<<"\n\t\t\t(1)\tEDIT QUESTIONS";
		cout<<"\n\t\t\t(2)\tEDIT OPTIONS";

		cout<<"\n\n"<<setw(50)<<"Enter choice (option number):\t";
		cin>>optn;

		switch(optn)
		{
			case 1:	cout<<"\n\t\t\tEnter new text: \n\n\t\t";
				gets(question);
				cout<<"\n\t\t\tEdit options as well? Y/N\t";
				cin>>choice;
				optn++;
				break;
			case 2: cout<<"\n\t\t\tEnter new options: \n";
				for (int i=0; i<4; i++)
				{
					cout<<"\n\t\t\t("<<i+1<<")\t";
					gets(opt[i]);
				}				cout<<"\n\t\tEnter correct answer (option number):\t";
				cin>>answer;
				cout<<"\n\t\t\tEdit question as well? Y/N\t";
				cin>>choice;
				optn--;
				break;
			default: cout<<"\n\t\t\t\t\tINVALID ENTRY";

		}

	}while(choice=='y'||choice=='Y');

} //End of INe

void test::OUT()
{
	cout<<"\n   "<<Qid<<".\t"<<question<<"\n\n";
	for(int i=0; i<4; i++)
	{
		cout<<"   ("<<i+1<<")  "<<opt[i];
	}
	cout<<"\n";

} //End of OUT()

void test::OUTt(int a)
{
	cout<<"\n   "<<a<<".\t"<<question<<"\n\n";

	for(int i=0; i<4; i++)
	{
		cout<<"   ("<<i+1<<")  "<<opt[i];
	}
	cout<<"\n";

} //End of OUTt()

long si=sizeof(test);
long si2=sizeof(applicant);

long int autogena()
{
	fstream f;
	long t, r;
	applicant obj;

	f.open("records.txt", ios::in|ios::out|ios::binary);

	if (f.fail())
	{
		cerr<<"\nFile couldn't be opened.";
		getch();
		exit(1);
	}

	f.seekg(0, ios::end);
	t=f.tellg();
	if(t==0)
	{
		r=1;
	}
	else
	{
		f.seekg(-si2, ios::end);
		f.read((char *)&obj, si2);
		r=obj.RetID();
		r++;
	}
	f.close();
	return r;

} //End of autogena()

int autogen()
{
	fstream f;
	long t;
	int r;
	test obj;

	f.open("ques.txt", ios::in|ios::out|ios::binary);

	if (f.fail())
	{
		cerr<<"\nFile couldn't be opened.";
		getch();
		exit(1);
	}

	f.seekg(0, ios::end);
	t=f.tellg();
	if(t==0)
	{
		r=1;
	}
	else
	{
		f.seekg(-si, ios::end);
		f.read((char *)&obj, si);
		r=obj.retid();
		r++;
	}
	f.close();
	return r;

} //end of autogen()

void HEAD()
{
	date d;
	getdate(&d);
	cout<<"\n   Speed Control\t\t\t\t\t\t"<<(int)d.da_day<<"/"<<(int)d.da_mon<<"/"<<d.da_year<<"\n";

} //End of HEAD()

void LOAD()
{
       clrscr();
       _setcursortype(0);
       HEAD();
       cout<<"\n\n";
       randomize();
       int c;
       c=random(8)+1;

       switch(c)
       { case 1: gotoxy(33,18);cout<<"DO YOU KNOW?\n\n\t   More than 1.2 million people die in road traffic every year.";
		 break;
	 case 2: gotoxy(33,18);cout<<"DO YOU KNOW?\n\n\t     Half of all crash victims are vulnerable road users like\n\t\t\t   pedestrians, cyclists, etc.";
		 break;
	 case 3: gotoxy(33,18);cout<<"DO YOU KNOW?\n\n\t     World's biggest congestion occured in France stretching\n\t\t   around 175 km from Lyon to Paris in 1980.";
		 break;
	 case 4: gotoxy(33,18);cout<<"DO YOU KNOW?\n\n\t      The very first traffic lights were a manually operated\n\t\t\t\t and gas lit.";
		 break;
	 case 5: gotoxy(33,18);cout<<"DO YOU KNOW?\n\n\t     In 1928, Charles Adler Jr invented traffic lights that\n\t\t   that could be operated by drivers honking.";
		 break;
	 case 6: gotoxy(33,18);cout<<"DO YOU KNOW?\n\n\t      Road congestion costs Europe 1% of its GDP every year.";
		 break;
	 case 7: gotoxy(33,18);cout<<"DO YOU KNOW?\n\n\t     One bus could carry the same number of people as 30 cars,\n\t        while only occupying the road space of three cars.";
		 break;
	 case 8: gotoxy(33,18);cout<<"DO YOU KNOW?\n\n\t     The average modern car engine emits 28 times less carbon\n\t\t\t monoxide than 20 years ago.";
		 break;
       }

       gotoxy(36,10);cout<<"LOADING";
       gotoxy(32,10);cout<<char(248);delay(200);
       gotoxy(32,9);cout<<char(248);delay(200);
       gotoxy(33,8);cout<<char(248);delay(200);
       gotoxy(35,7);cout<<char(248);delay(200);
       gotoxy(37,6);cout<<char(248);delay(200);
       gotoxy(41,6);cout<<char(248);delay(200);
       gotoxy(43,7);cout<<char(248);delay(200);
       gotoxy(45,8);cout<<char(248);delay(200);
       gotoxy(46,9);cout<<char(248);delay(200);
       gotoxy(46,10);cout<<char(248);delay(200);
       gotoxy(46,11);cout<<char(248);delay(200);
       gotoxy(45,12);cout<<char(248);delay(200);
       gotoxy(43,13);cout<<char(248);delay(200);
       gotoxy(41,14);cout<<char(248);delay(200);
       gotoxy(37,14);cout<<char(248);delay(200);
       gotoxy(35,13);cout<<char(248);delay(200);
       gotoxy(33,12);cout<<char(248);delay(200);
       gotoxy(32,11);cout<<char(248);delay(200);

       gotoxy(10,10);
       clreol();

       gotoxy(36,8);
       cout<<"\n\n\t\t\t  PRESS A KEY TO CONTINUE";
       getch();

} //End of LOAD()

void ADMIN();

int pass()
{
	char p[20], mp[]="agnel1234";
	int i, a=0;

  pass: clrscr();
	HEAD();

	cout<<"\n\n\n\n\n\n\n\n                              PASSWORD: ";

	for(i=0; i<9; i++)
	{
		p[i]=getch();
		cout<<"*";
	}

	p[i]='\0';

	if(strcmp(p,mp)==0)
	{
	    cout<<"\n\n                                Access Granted.";
	    cout<<"\n\n                          Press any key to proceed...";
	    getch();
	    ADMIN();
	    return 0;
	}
	else
	{
		cout<<"\n\n                                Access Denied!";
		a++;
		getch();

		if(a<3)
			goto pass;

		else
		{
			return 1;

		}
	}

} // End of pass()

void addq()
{
	fstream f;
	test obj;
	int r;
	r=autogen();

	obj.IN(r);

	f.open("ques.txt", ios::app|ios::binary);

	if (f.fail())
	{
		cerr<<"\nThe file couldn't be opened for writing";
		getch();
		exit(1);
	}

	f.write((char *)&obj, si);
	f.close();

} //end of addq();

void delq()
{
	fstream f1,f2;
	test obj;
	int r, flag=0;

	cout<<"\nEnter the ID of the question to be deleted: ";
	cin>>r;

	f1.open("ques.txt", ios::in|ios::binary);

	if (f1.fail())
	{
		cerr<<"\nThe file couldn't be opened for reading";
		getch();
		exit(1);
	}

	f2.open("temp.txt", ios::out|ios::binary);

	if (f2.fail())
	{	cerr<<"\nThe temporary file couldn't be opened for writing";
		getch();
		exit(1);
	}

	while(f1.read((char*)&obj, si))
	{
		if(obj.retid()!=r)
		{
			f2.write((char *)&obj, si);
		}
		else
		{
			flag=1;
		}
	}

	if(flag==1)
	{
		cout<<"\nThe question was successfully deleted.";
	}
	else
	{
		cout<<"\nThere is no question with ID "<<r<<" in SPEED CONTROL database.";
	}

	f1.close();
	f2.close();

	remove("ques.txt");
	rename("temp.txt","ques.txt");

} //end of delq()

void edit()
{
	fstream f;
	test obj;
	int r, flag=0;

	f.open("ques.txt", ios::in|ios::out|ios::binary);

	if (f.fail())
	{
		cerr<<"\nThe file couldn't be opened for editing";
		getch();
		exit(1);
	}

	cout<<"\n\n\t\tEnter the ID of the question to be edited: \t";
	cin>>r;

	while(f.read((char*)&obj,si))
	{
		if(obj.retid()==r)
		{
			flag=1;
			f.seekp(-si, ios::cur);
			cout<<"\nOriginal question:\n";
			obj.OUT();
			obj.INe();
			f.write((char *)&obj, si);
			break;
		}
	}

	if(flag==1)
		cout<<"\n\n\t\t\tThe question has been altered.\n";
	else
		cout<<"\n\n\t\t\tQuestion with ID "<<r<<" not found.\n";

	f.close();

} //end of edit();

void dispq()
{
	fstream f;
	test obj;

	f.open("ques.txt", ios::in|ios::binary);

	if (f.fail())
	{
		cerr<<"\nThe file couldn't be opened for reading";
		getch();
		exit(1);
	}

	while(f.read((char*)&obj,si))
	{
		obj.OUT();
		cout<<"\n\tCORRECT ANSWER:\t("<<obj.RetAns()<<")\n";
		getch();
	}

	f.close();

} //end of dispq();

void RegC()
{
	fstream f;
	applicant obj;

	clrscr();
	HEAD();
	cout<<endl<<endl<<endl;

	obj.INa();

	f.open("records.txt", ios::app|ios::binary);

	if (f.fail())
	{
		cerr<<"\n\n\t\t\tThe file couldn't be opened.";
		getch();
		exit(1);
	}

	f.write((char *)&obj, si2);

	f.close();

} //end of RegC();

void RESULT()
{
	fstream f;
	applicant obj, obj1;
	int n, flag=0;
	long ID;

	clrscr();
	HEAD();
	cout<<"\n\n";

	cout<<"\n\n\t\t    Enter ID of Candidate:\t";
	cin>>ID;

	f.open("records.txt", ios::in|ios::binary);

	if (f.fail())
	{
		cerr<<"\n\tThe file couldn't be opened for reading";
		getch();
		exit(1);
	}

	while(f.read((char*)&obj1,si2))
	{

		if(obj1.RetID()==ID)
		{
			flag=1;

			clrscr();
			HEAD();

			cout<<"\n\n\n\n";
			cout<<setw(6)<<"ID"<<setw(25)<<"CANDIDATE'S NAME";
			cout<<setw(25)<<"#CORRECT ANSWERS";
			cout<<setw(20)<<"RESULT\n";

			for(n=0; n<80; n++)
				cout<<(char)196;

			cout<<"\n";
			obj1.OUT();

			getch();
			break;

		} //End of if() #1

	} //End of while()

	f.close();

	if(flag==0)
	{
		cout<<"\n\n\t\tYou are not registered in Speed Control user database.";
		getch();
	}

} //End of RESULT()

void DETAIL()
{
	fstream f;
	applicant obj1;
	int n;

	clrscr();
	HEAD();
	cout<<"\n\n";

	f.open("records.txt", ios::in|ios::binary);

	if (f.fail())
	{
		cerr<<"\n\tThe file couldn't be opened for reading";
		getch();
		exit(1);
	}

	clrscr();
	HEAD();

	cout<<"\n\n";
	cout<<setw(6)<<"ID"<<setw(25)<<"CANDIDATE'S NAME";
	cout<<setw(25)<<"#CORRECT ANSWERS";
	cout<<setw(20)<<"RESULT\n";

	for(n=0; n<80; n++)
		cout<<(char)196;

	while(f.read((char*)&obj1,si2))
	{

			cout<<"\n";
			obj1.OUT();

	} //End of while()

	f.close();

	getch();

}  //End of DETAIL()

void editC()
{
	fstream f;
	applicant obj;
	long int ID;
	int flag=0;

	f.open("records.txt", ios::in|ios::out|ios::binary);

	cout<<"\n\t\t\tEnter ID of Candidate:\t";
	cin>>ID;

	while(f.read((char *)&obj, si2))
	{
		if(obj.RetID()==ID)
		{
			flag=1;
			f.seekg(-si2, ios::cur);
			obj.INe();
			f.write((char *)&obj, si2);
			break;
		}

	}

	f.close();

	if(flag==1)
	{
		cout<<"\n\n\t\t\tInformation successfully edited";
	}
	else
		cout<<"\n\n\t\tRecord does not exist in Speed Control user database";

} //End of editC()

void Cand()
{
	char choice;
	int cho;

	p2:

	do
	{
		clrscr();
		HEAD();

		cout<<"\n\n\t\t\t\tCANDIDATES' MENU";
		cout<<"\n\n\n\t\t\t(1)\tRegister Candidate";
		cout<<"\n\n\t\t\t(2)\tResult";
		cout<<"\n\n\t\t\t(3)\tDetails";
		cout<<"\n\n\t\t\t(4)\tEdit Candidates' Details";
		cout<<"\n\n\t\t\t(5)\tBack to Previous Page";

		cout<<"\n\n\n\n\t\t\tEnter your option:\t";
		cin>>cho;

		switch(cho)
		{
			case 1: RegC();
				goto p2;

			case 2: RESULT();
				break;

			case 3: DETAIL();
				break;

			case 4: editC();
				break;

			case 5: return;

			default: cout<<"\n\n\t\tOption does not exist.";

		}

		cout<<"\n\n\n\t\t\tDo you wish to continue? (Y/N)  ";
		cin>>choice;


	}while(choice=='y'||choice=='Y');


} //End of Cand()

void ADMIN()
{
	clrscr();

	int opt;
	char choice, cho, cho1;

     pg:do
	{
	   clrscr();
	   HEAD();
	   cout<<"\n\n\n\t\t\t    ADMINISTRATOR'S MENU\n\n\n";
	   cout<<setw(40)<<"\t(A)\tCANDIDATES\n\n";
	   cout<<setw(40)<<"\t(B)\tQUESTION MAKER\n\n";
	   cout<<setw(40)<<"\t\t(C)\tRETURN TO MAIN MENU\n\n";

	   cout<<"\n\n\n"<<setw(40)<<"Enter option:  ";
	   cin>>cho;
	   switch(cho)
	   {
	       case 'a':

	       case 'A':clrscr();
			HEAD();
			Cand();
			goto pg;

	       case 'b':

	       case 'B':do
			{	clrscr();
				HEAD();
				cout<<"\n\n\n\t\t\t   ADMINISTRATOR'S MENU\n\n\n";
				cout<<setw(40)<<"\t1)\tADD A QUESTION\n\n";
				cout<<setw(40)<<"\t2)\tDELETE A QUESTION\n\n";
				cout<<setw(40)<<"\t3)\tEDIT A QUESTION\n\n";
				cout<<setw(40)<<"\t\t4)\tDISPLAY ALL QUESTIONS\n\n";
				cout<<setw(33)<<"\t\t\t5)\tBACK TO PREVIOUS PAGE\n\n";

				cout<<"\n\n\n"<<setw(50)<<"Enter option number:  ";
				cin>>opt;

				switch(opt)
				{
					case 1: addq();
						break;
					case 2: delq();
						break;
					case 3: edit();
						break;
					case 4: dispq();
						break;
					case 5: goto pg;

					default: cout<<"\n\t\t\tYour entry is not valid";

				}

				cout<<"\n\n\t\t\tDo You wish to continue? Y/N\t";
				cin>>cho1;

			}while(cho1=='y'||cho1=='Y');

			goto pg;


	       case 'c':

	       case 'C':return;

	       default:cout<<"\n\t\t\tOption does not exist";
	   }
	   cout<<"\n\n\t\t\tDo you wish to continue? (Y/N) :\t";
	   cin>>choice;

	}while(choice=='y'||choice=='Y');

} //End of ADMIN()

int QN(int NQ)
{
	randomize();
	return (random(NQ)+1);

} //End of QN()

void qpaper(int a[5])
{
	int i, j, flag=0, r=0;	
	int NQ;
	fstream f;
	test obj;

	f.open("ques.txt", ios::in|ios::binary);

	if (f.fail())
	{
		cerr<<"\n\tThe file couldn't be opened for reading";
		getch();
		exit(1);
	}

	f.seekg(-si, ios::end);
	f.read((char*)&obj, si);
	NQ=(obj.retid());

	f.close();

	for(i=0; i<5; i++)
	{

		a[i]=QN(NQ);

		for(j=0; j<i; j++)
		{
			if(a[j]==a[i])
			{
			     i--;
			     r=1;
			     break;
			}
		}

		if(r==1)
		{
			continue;
		}

		

		flag=0;

	} //End of for()

} //End of qpaper()

int QUES() //returns no. of question attempted correctly
{
	int optn, i=0, c=0, k=0;
	char choice;
	int a[5];
	fstream f;
	test obj;

	qpaper(a);

	for(i=0; i<5; i++)
	{
		do
		{
			clrscr();
			HEAD();

			cout<<"\n\n\n"<<setw(75)<<c<<"/"<<k<<"\n";

			f.open("ques.txt", ios::in|ios::binary);

			if(f.fail())
			{
				cerr<<"\n\n\tFile couldn't be opened for reading";
				getch();
				exit(1);
			}

			f.seekg(0, ios::beg);

			while(f.read((char*)&obj,si))
			{
				if(obj.retid()==a[i])
				{
					obj.OUTt(i+1);
					break;
				}
			}

			f.close();

			cout<<"\n\n\t\t\tEnter your choice:\t";
			cin>>optn;

			if(CHECK(optn))
			{
				cout<<"\n\n\t\t\tEnter your choice:\t";
				cin>>optn;
			}

			cout<<"\n\n\t\tPress < P > to proceed.";
			cout<<"\n\t\tPress < C > to change you answer\t";
			choice=getch();

		}while(choice=='C'||choice=='c');

		if(optn==obj.RetAns())
		{
			c++;
		}

		k++;


	}//end of for()

	clrscr();
	HEAD();

	return c;

} //End of QUES()

void TEST()
{
	int flag=0, n;
	applicant obj, obj1;
	fstream f,f2;

	b:

	clrscr();
	HEAD();
	cout<<"\n\n";

	obj.IN();

	f.open("records.txt", ios::in|ios::binary);

	if (f.fail())
	{
		cerr<<"\n\tThe file couldn't be opened for reading";
		getch();
		exit(1);
	}

	while(f.read((char*)&obj1,si2))
	{
		if(obj1.RetID()==obj.RetID())
		{
			flag=1;
			if(strcmpi(obj1.RetName(),obj.RetName())==0)
			{
				flag=2;
			}
			break;
		}

		if(strcmpi(obj1.RetName(),obj.RetName())==0)
		{
			flag=1;
			if(obj1.RetID()==obj.RetID())
			{
				flag=2;
			}
		}
	}

	f.close();

	if(flag==0)
	{
		cout<<"\n\n\t\tYou are not registered in Speed Control user database.";
		getch();
		return;
	}
	else if(flag==1)
	{
		cout<<"\n\n\t\tName - ID Mismatch. Enter name and ID again.";
		getch();
		goto b;
	}

	LOAD();

	n=QUES();
	obj.SetQA(n);
	obj.SetResult();

	f2.open("records.txt", ios::in|ios::out|ios::binary);

	if (f2.fail())
	{
		cerr<<"\n\tThe file couldn't be opened";
		getch();
		exit(1);
	}

	while(f2.read((char *)&obj1,si2))
	{
		if(obj1.RetID()==obj.RetID())
		{
			f2.seekp(-si2, ios::cur);
			f2.write((char *)&obj, si2);
			break;
		}
	}

	f2.close();

	cout<<"\n\n\n\t\t\tYou have finished your test!";
	cout<<"\n\n\n\t\t\t   PRESS <ENTER> TO PROCEED";
	getch();

	clrscr();
	HEAD();

	if(obj.RetRes()=='P')
	{
		cout<<"\n\n\n\n\t\t    CONGRATULATIONS. you have passed!";
		obj.DispRes();
	}

	else
	{
		cout<<"\n\n\n\n\t\t    Sorry, you didn't make it.";
		obj.DispRes();
	}

	getch();

} //End of TEST()

//////////////////////////////////////////////////////

void main()
{
	int opt;
	char choice;

	clrscr();

	cout<<"\n\n\n\n\n\n\n\n"<<setw(120)<<"\tSPEED CONTROL\n\n";
	cout<<setw(65)<<"...Preventing vehicle related deaths since 1998\n\n";

	cout<<setw(48)<<"Welcome to Database";
	getch();

	LOAD();

	clrscr();
	HEAD();

	int left=23, right=55, top=5, bottom=15, ps=0;
	p:

	clrscr();
	HEAD();

	gotoxy(23,5);
	cout<<char(201);

	for(int z=1; z<right-left; z++)
	{
		 cout<<char(205);
	}
	cout<<char(187);
	cout<<"\n\n\t\t\t  * * * * MAIN MENU * * * *\n\n";
	cout<<setw(34)<<"\t\t(1)  ADMIN";
	cout<<"\n\n"<<setw(34)<<"\t\t(2)  TAKE TEST";
	cout<<"\n\n"<<setw(34)<<"\t(3)  EXIT";

	for(int i=1; i<bottom-top; i++)
	{
		 gotoxy(left,top+i);cout<<char(186);
		 gotoxy(right,top+i);cout<<char(186);
	}

	gotoxy(left,bottom);
	cout<<char(200);

	for(i=1; i<right-left; i++)
	{
		 cout<<char(205);
	}
	cout<<char(188);

	cout<<"\n\n\n"<<setw(50)<<"Enter option number:  ";
	cin>>opt;

	switch(opt)
	{
		case 1: if(ps==0)
			{
				ps=pass();
			}

			if(ps==1)
			{
				clrscr();
				HEAD();
				cout<<"\n\n\n\tYou are not authorized to access the administrator's menu";
				getch();
				goto p;
			}
			goto p;

		case 2: TEST();
			goto p;

		case 3: exit(0);

		default: cout<<"\n"<<setw(51)<<"Your entry is not valid";

	}

} //End of main()
