#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//len,brd,ht are integers representing the dimensions of the box

class Box {
    private:
        long len, brd, ht;
    public:
        Box() { len=0; brd=0; ht=0; }
        Box(int l,int b,int h) {
            len = l;
            brd = b;
            ht = h;
        }
        Box(Box &B) {
            len  = B.len;
            brd = B.brd;
            ht = B.ht;
        }

        int getLength() { 
            return len; 
        } // Return box's length
        
        int getBreadth() { 
            return brd; 
            } // Return box's breadth
        
        int getHeight() { 
            return ht; 
            }  //Return box's height
        
        long long CalculateVolume() {
        return (long long)len * brd * ht;
        } // Return the volume of the box

        //Overload operator < as specified
        friend bool operator<(Box& a, Box& b) {
            if (a.len < b.len) {
                return true;
            } else if ( a.len == b.len && a.brd < b.brd) {
                    return true;
            } else if (a.len == b.len && a.brd == b.brd && a.ht < b.ht) {
                    return true;
            } else{
                    return false;
            }  
        }

        //Overload operator << as specified
        friend ostream& operator<<(ostream &out, Box& Bx) {
            out << Bx.getLength() << " " << Bx.getBreadth() << " " << Bx.getHeight();
            return out;
        }
};


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}