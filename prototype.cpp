#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class admin
{
    private:
        string username;
        string pass;
    public:
    
        void login()
        {
            while (pass!="password" && username!="Admin")
            {  
                cout<<"Enter your username:";
                cin>>username;
                cout<<"Enter your password:";
                cin>>pass;
                if (pass!="password" && username!="Admin")
                {
                    cout<<"Invalid password!!\ntry again!!\n\n";
                }
            }  
        }
};
class jewellery
{
    public:
        static int nextitem;
        string itemcode,itemname;
        int goldprice; //current price of gold for each gram in inr
        double weight,karat,stone,finalprice,stoneprice,qty;
        int item;
        jewellery()
        {
            goldprice=7700;
            item=nextitem++;
            finalprice = calculateprice();
            stoneprice=calculatestoneprice();
            itemcode = "jw"+ itemname + to_string(item);
        }
        void input()
        {
            cout<<"Enter jewellry name:";
            cin>>itemname;
            cout<<"Enter gold weight of jewellery in grams:";
            cin>>weight;
            cout<<"select your stone:\n1)Diamond\n2)Emerald\n3)ruby\n4)Opal\n5)no stone"<<endl;
            cin>>stone;
            cout<<"Enter Quantity:";
            cin>>qty;
            cout<<"Enter gold purity \n 1)23+\n 2)18 \n3)lesser  :";
            cin>>karat;
        }
        double calculatestoneprice()
        {
        	int stone;
        	printf("Enter the stone");
        	scanf("%d",&stone);
        	switch(stone)
        	{
        		case 1:
        			{
        				return 25000;
        				break;
					}
					
					case 2:
        			{
        				return 15000;
        				break;

					}
					
					case 3:
        			{
        				return 20000;
        				break;
					}
					
					case 4:
        			{
        				return 10000;
        				break;
					}
					
					default:
        			{
        				return 1;
        				break;
					}
			}
            
        }
        double calculatekarat()
        {
        	
        	int karat;
        	printf("Enter the karat");
        	scanf("%d",&karat);
        	switch(karat)
        	{
        		case 1:
        			{
        				return 0.95;
        				break;
					}
					
					case 2:
        			{
        				return 0.75;
        				break;
					}
					
					case 3:
        			{
        				return 0.5;
        				break;
					}
					
					
					
					default:
        			{
        				break;
					}
			}
            
        }
        int calculateprice()
        {
            return calculatekarat()*goldprice*weight+calculatestoneprice();
        }
        void displaydetails()
        {
            cout<<"Jewellry name:"<<itemname<<endl;
            cout<<"Jwellry code:"<<itemcode<<endl;
            cout<<"Price:"<<calculateprice()<<"INR"<<endl;
        }
        void writefile()
        {
            ofstream ofile("details.txt",ios::app);
            if (!ofile)
            {
                cerr<<"failed to open file!!";
            }
            else
            {
                ofile<<"Jewellry name:"<<itemname<<endl;
                ofile<<"Jwellry code:"<<itemcode<<endl;
                ofile<<"Price:"<<calculateprice()<<"INR"<<endl;
            }  
        }
};
int jewellery::nextitem =1001;
int main()
{
    admin*ptra = new admin;
    ptra->login();
    delete ptra;
    jewellery j;
    j.input();
    j.displaydetails();
    j.writefile();
    return 0;
}