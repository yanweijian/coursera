/*************************************************************************
    > File Name: warriors.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: 2018年03月03日 星期六 17时50分35秒
 ************************************************************************/

#include<iostream>
using namespace std;

class warriors{
	public:
	int totalEnergy;
	int dragonEnergy;
	int icemanEnergy;
	int wolfEnergy;

	int warriorNum;
	int dragonNum;
	int icemanNum;
	int wolfNum;

	warriors(int totalEnergy_,int dragonEnergy_,int icemanEnergy_,int wolfEnergy_,int warriorNum_=0,int dragonNum_=0,int icemanNum_=0,int wolfNum_=0):totalEnergy(totalEnergy_),dragonEnergy(dragonEnergy_),icemanEnergy(icemanEnergy_),wolfEnergy(wolfEnergy_),warriorNum(warriorNum_),dragonNum(dragonNum_),icemanNum(icemanNum_),wolfNum(wolfNum_){

	}
	
	int productWarriors(){
	if(totalEnergy>=dragonEnergy){
		warriorNum++;
		dragonNum++;
		totalEnergy-=dragonEnergy;
		cout<<"dragon "<<warriorNum<<" born with "<<dragonEnergy<<"energy,"<<dragonNum<<" dragon in ";
		return 1;
	}
	else if(totalEnergy>=icemanEnergy){
		warriorNum++;
		totalEnergy-=icemanEnergy;
		icemanNum++;
		cout<<"iceman "<<warriorNum<<" born with "<<icemanEnergy<<" energy,"<<icemanNum<<" iceman in ";
		return 1;
	}
	else if(totalEnergy>=wolfEnergy){
		warriorNum++;
		totalEnergy-=wolfEnergy;
		wolfNum++;
		cout<<"wolf "<< warriorNum<<" born with"<<wolfEnergy<<" energy,"<<wolfNum<<" wolf in ";
		return 1;
	}
	else{
		cout<<"stop product warriors ";
			return -1;
	}
	}
};

int main()
{
	int ntotal,ndragon,nice,nwolf;
	cout<<"please input the totalEnergy,dragonEnergy,icemanEnergy,wolfEnergy"<<endl;
	cin>>ntotal>>ndragon>>nice>>nwolf;
	warriors red(ntotal,ndragon,nice,nwolf);
	
    int time=0;
	cout<<time<<" red ";
	while(red.productWarriors()>0){
		time++;
		cout<<" red head "<<endl;
		cout<<time<<" red ";
	};
	cout<<"red head"<<endl;
	return 0;
}

