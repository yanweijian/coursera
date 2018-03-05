/*************************************************************************
    > File Name: warriorProduct.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Sat 06 Jan 2018 01:38:29 PM DST
 ************************************************************************/

#include<iostream>
using namespace std;

class RedWarrior{
	public:
		int rtotalEnergy;
		int rdragonEnergy;
		int rdragonNum;
		int rninjaEnergy;
		int rninjaNum;
		int ricemanEnergy;
		int ricemanNum;

		RedWarrior(int total,int dragon,int ninja,int iceman,int dnum=0,int nnum=0,int inum=0):rtotalEnergy(total),rdragonEnergy(dragon),rninjaEnergy(ninja),ricemanEnergy(iceman),rdragonNum(dnum),rninjaNum(nnum),ricemanNum(inum){

		}

/*		RedWarrior(int rtotal,int dragon,int dnum=0):rtotalEnergy(rtotal),rdragonEnergy(dragon),rdragonNum(dnum){

		}
*/
		int productWarriors(){
			if(rtotalEnergy>=rdragonEnergy){
	
				rtotalEnergy-=rdragonEnergy;
				rdragonNum++;
				cout<<"red dragon "<<rdragonNum<<" born with strength "<<rdragonEnergy<<endl;
				cout<<"remain "<<rtotalEnergy<<endl;
				return 1;
			}
			else if(rtotalEnergy>=rninjaEnergy){
				rtotalEnergy-=rninjaEnergy;
				rninjaNum++;
				cout<<"red ninja "<<rninjaNum<<" born with strengh "<<rninjaEnergy<<endl;
				cout<<"remain "<<rtotalEnergy<<endl;
				return 1;
			}
			else if(rtotalEnergy>=ricemanEnergy){
				rtotalEnergy-=ricemanEnergy;
				ricemanNum++;
				cout<<"red iceman "<<ricemanNum<<" born with strength "<<ricemanEnergy<<endl;
				cout<<"remain "<<rtotalEnergy<<endl;
				return 1;
			}
			else{
				cout<<"no energy "<<endl;
				return 0;
			}
		}
};

int main()
{
	//RedWarrior red;
	int rtotal;
	int rdragon,rninja,riceman,dnum=0,nnum=0,inum=0;
	cin>>rtotal>>rdragon>>rninja>>riceman;
	RedWarrior red(rtotal,rdragon,rninja,riceman,dnum,nnum,inum);
//	cin>>rtotal>>rdragon>>dnum;
//	RedWarrior red(rtotal,rdragon,dnum);
	while(red.productWarriors()){

	}
	//RedWarrior::rtotalEnergy=rtotal;
	//red::RedWarrior(rtotal,rninja,riceman);
	//red.productWarriors;
}
