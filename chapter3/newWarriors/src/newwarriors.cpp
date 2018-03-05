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
		cout<<"red dragon "<<warriorNum<<" born with "<<dragonEnergy<<"energy,"<<dragonNum<<" dragon in red"<<endl;
		return 1;
	}
	else if(totalEnergy>=icemanEnergy){
		warriorNum++;
		totalEnergy-=icemanEnergy;
		icemanNum++;
		cout<<"red iceman "<<warriorNum<<" born with "<<icemanEnergy<<" energy,"<<icemanNum<<" iceman in red"<<endl;
		return 1;
	}
	else if(totalEnergy>=wolfEnergy){
		warriorNum++;
		totalEnergy-=wolfEnergy;
		wolfNum++;
		cout<<"red wolf "<< warriorNum<<" born with"<<wolfEnergy<<" energy,"<<wolfNum<<" wolf in red "<<endl;
		return 1;
	}
	else{
		cout<<"red stop product warriors "<<endl;
			return -1;
	}
	}
};

class newwarriors:public warriors{
	public:
		newwarriors(int totalEnergy_,int dragonEnergy_,int icemanEnergy_,int wolfEnergy_,int warriorNum_=0,int dragonNum_=0,int icemanNum_=0,int wolfNum_=0):warriors(totalEnergy_, dragonEnergy_, icemanEnergy_, wolfEnergy_,warriorNum_ , dragonNum_, icemanNum_, wolfNum_){

		}

		int productWarriors(){
	if(totalEnergy>=dragonEnergy){
		warriorNum++;
		dragonNum++;
		totalEnergy-=dragonEnergy;
		cout<<"blue dragon "<<warriorNum<<" born with "<<dragonEnergy<<"energy,"<<dragonNum<<" dragon in blue"<<endl;
		return 1;
	}
	else if(totalEnergy>=wolfEnergy){
		warriorNum++;
		totalEnergy-=wolfEnergy;
		wolfNum++;
		cout<<"blue wolf "<< warriorNum<<" born with"<<wolfEnergy<<" energy,"<<wolfNum<<" wolf in blue"<<endl;
		return 1;
	}
	else if(totalEnergy>=icemanEnergy){
		warriorNum++;
		totalEnergy-=icemanEnergy;
		icemanNum++;
		cout<<"blue iceman "<<warriorNum<<" born with "<<icemanEnergy<<" energy,"<<icemanNum<<" iceman in blue"<<endl;
		return 1;
	}
	
	else{
		cout<<"blue stop product warriors "<<endl;
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
	newwarriors blue(ntotal,ndragon,nice,nwolf);

    int time=0;
	int redflag=1;
	int blueflag=1;
	while((redflag|blueflag)>0){
		time++;
		if(redflag){
			cout<<time<<" ";
			redflag=red.productWarriors();
		}
		
		if(blueflag){
			cout<<time<<" ";
			blueflag=blue.productWarriors();
		}
	}
	
	return 0;
}


