#include<queue>
#include<vector>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 20

class dPCB{
	public:
	int pid,atime,ptime,rank;
	void Read(int a,int b,int c,int d){
		pid = a,
		atime = b,
		ptime = c,
		rank = d;
	}
	void Display(){
		printf("------------\n");
		printf("PID:\t%d\n",pid);
		printf("Arrive_Time:\t%d\n",atime);
		printf("Process_Time:\t%d\n",ptime);
		printf("Rank:\t%d\n",rank);
		printf("------------\n");
	}
};

dPCB dlist[MAXN];
int dp = 0;

void Display(int a,int b){
	for(int i = a;i < b;i++){
		printf("#%d\n",i);
		dlist[i].Display();
	}
}

void Ans() { 
	/*
	int timestamp = 0;

	for(int i = 0;i < dp;i++) {
		printf("%d/%d/%d/%d/%d\n",i+1,dlist[i].pid,timestamp,timestamp+dlist[i].ptime,dlist[i].rank);
		timestamp += dlist[i].ptime;
	}
	*/

}

bool cFCFS(const dPCB &A, const dPCB &B) {
	if(A.atime == B.atime) return A.pid < B.pid;
	else return A.atime < B.atime;
}

void DR(int time_piece){
	sort(dlist, dlist+dp, cFCFS);
	vector<dPCB> queue;
	dPCB cTask;
	queue.push_back(dlist[0]);
	int lp = 1;

	while(!queue.empty() || lp < dp){
		if(queue.empty()){
			:w


		}
	}	
}

void RR(int time_piece){
	sort(dlist, dlist+dp, cFCFS);
	queue<dPCB> queue;
	dPCB cTask;
	int tick = 0, list_point = 1;
	int tc = time_piece,cNum = 1,gtime = dlist[0].atime;
	queue.push(dlist[0]);

	while(list_point < dp || !queue.empty()){
		if(queue.empty()) queue.push(dlist[list_point++]);
		cTask = queue.front();
		queue.pop();

		while(dlist[list_point].atime <= gtime+time_piece && list_point < dp) queue.push(dlist[list_point++]);

		if(gtime < cTask.atime) gtime = cTask.atime;
		
		if(cTask.ptime > time_piece){
			printf("%d/%d/%d/%d/%d\n",cNum++, cTask.pid, gtime, gtime+time_piece, cTask.rank);
			cTask.ptime -= time_piece;
			gtime += time_piece;
			queue.push(cTask);
		}else{
			printf("%d/%d/%d/%d/%d\n",cNum++, cTask.pid, gtime, gtime+cTask.ptime, cTask.rank);
			gtime += cTask.ptime;
			cTask.ptime = 0;
		}
	}
}

void FCFS(){
	sort(dlist, dlist+dp, cFCFS);
	int gtime = dlist[0].atime;
	for(int i = 0;i < dp;i++){
		printf("%d/%d/%d/%d/%d\n",i+1, dlist[i].pid, gtime, gtime+dlist[i].ptime, dlist[i].rank);
		gtime += dlist[i].ptime;
	}
}

struct cSRTF{
	bool operator() (dPCB A, dPCB B) {
		if(A.ptime == B.ptime){
			if(A.atime == B.atime) return A.pid > B.pid;
			else return A.atime > B.atime;
		}else return A.ptime > B.ptime;
	}	
};

void SJF(){
	sort(dlist, dlist+dp, cFCFS);
	priority_queue<dPCB, vector<dPCB>, cSRTF> queue;
	dPCB cTask = dlist[0];

	queue.push(dlist[0]);
	int gtime = dlist[0].atime, cNum = 1;
	for(int i = 1;i < dp || !queue.empty();i++){
		cTask = queue.top();
		
		printf("%d/%d/%d/%d/%d\n",cNum++, cTask.pid, gtime, gtime+cTask.ptime, cTask.rank);	
		gtime += cTask.ptime;
		queue.pop();
		while(i < dp && dlist[i].atime <= cTask.atime+cTask.ptime){
			queue.push(dlist[i++]);
		}
		
	}
}

void SRTF(){
	sort(dlist, dlist+dp, cFCFS);
	int list_point = 0, gtime = 0, cNum = 1;
	priority_queue<dPCB, vector<dPCB>, cSRTF> queue;

	dPCB cTask;

	queue.push(dlist[0]);
	gtime = dlist[0].atime;

	for(int i = 1;i < dp;i++){
		cTask = queue.top();

		if(queue.empty()) gtime = dlist[i].atime;
		else if(gtime < cTask.atime) gtime = cTask.atime;

		while(gtime < dlist[i].atime && !queue.empty()){
			if(cTask.ptime <= dlist[i].atime-gtime){
				printf("%d/%d/%d/%d/%d\n",cNum++, cTask.pid, gtime, gtime+cTask.ptime, cTask.rank);
				gtime += cTask.ptime;
				queue.pop();
				
				if(!queue.empty()) cTask = queue.top();
			}else{
				if(cTask.ptime+gtime - dlist[i].atime > dlist[i].ptime){
					printf("%d/%d/%d/%d/%d\n",cNum++, cTask.pid, gtime, dlist[i].atime, cTask.rank);
					cTask.ptime -= dlist[i].atime-gtime;
					gtime = dlist[i].atime;
					queue.pop();
					queue.push(cTask);
				}else break;
			}
		}
		queue.push(dlist[i]);
	}

	while(!queue.empty()){
		cTask = queue.top();
		if(gtime < cTask.atime) gtime = cTask.atime;
		printf("%d/%d/%d/%d/%d\n",cNum++, cTask.pid, gtime, gtime+cTask.ptime, cTask.rank);
		gtime += cTask.ptime;
		queue.pop();
	}
}

int main(){
	int mode = 0,timepie = 0;
	scanf("%d",&mode);
	int a,b,c,d,e,N = 0;
	while(scanf("%d/%d/%d/%d/%d",&a,&b,&c,&d,&e)!=EOF){
		dlist[dp++].Read(a,b,c,d);
		timepie = e;
	}
	
	/*for(int i = 0;i < dp;i++){
		dlist[i].Display();
	}*/

	// Display(0,dp);
	switch(mode){
		case 1:
			FCFS();
			break;
		case 2:
			SJF();
			break;
		case 3:
			SRTF();
			break;
		case 4:
			RR(timepie);
			break;
		case 5:
			printf("no\n");
			break;
		default:
			break;
	}
	Ans();
	return 0;
}


