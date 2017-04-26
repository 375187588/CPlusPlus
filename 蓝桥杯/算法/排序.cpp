#include<iostream>
using namespace std;
int main(){
	int x,y,z;
	cin>>x>>y>>z;
	if(x<y){
		int temp=x;
		x=y,y=temp;}
	if(x<z){
		int temp=x;
		x=z,z=y,y=temp;}
	else if(y<z){
		int temp=y;
		y=z,z=temp;}
	cout<<x<<" "<<y<<" "<<z;
	return 0;}
