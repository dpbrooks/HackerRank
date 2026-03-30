/*
 * Create a custom class Box and overload operators '<' and '<<'
 * to allow Box objects to be compared and printed
 */
#include<bits/stdc++.h>

using namespace std;
//Implement the class Box 
class Box {
    
//l,b,h are integers representing the dimensions of the box
private:
    int l, b, h;
    
// The class should have the following functions : 
public:
    // Constructors: 
    // Box();
    Box() {
        l = 0;
        b = 0;
        h = 0;
    }
    
    // Box(int,int,int);
    Box(int len, int breadth, int height) {
        l = len;
        b = breadth;
        h = height;
    }
    
    // Box(Box);
    Box(Box& B) {
        l = B.getLength();
        b = B.getBreadth();
        h = B.getHeight();
    }

    // int getLength(); // Return box's length
    int getLength() {
        return l;
    }
    // int getBreadth (); // Return box's breadth
    int getBreadth() {
        return b;
    }
    // int getHeight ();  //Return box's height
    int getHeight() {
        return h;
    }
    // long long CalculateVolume(); // Return the volume of the box
    long long CalculateVolume() {
        long long vol = (long long) l * b * h;
        return vol;
    }

    //Overload operator < as specified
    //bool operator<(Box& b)
    bool operator<(Box& box) {
        if (l < box.getLength()) {
            return true;
        } else if (l == box.getLength() && b < box.getBreadth()) {
            return true;
        } else if (l == box.getLength() && b == box.getBreadth() && h < box.getHeight()) {
            return true;
        } else {
            return false;
        }
    }
};



//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)
ostream& operator<<(ostream& out, Box& B) {
    out << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
    return out;
}


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