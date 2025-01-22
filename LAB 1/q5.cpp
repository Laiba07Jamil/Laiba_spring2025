#include<iostream>
#include<cstring>
using namespace std;

struct Events{
	char event_name[20];
	char event_date[20];
	char venue[20];
	char organizer[20];
};

void searching_date(struct Events *events ,char search_date[],int num);

int main(){
	int num;
	cout<<"Enter the number of Events:";
	cin>>num;
	struct Events *events;
	events = new struct Events[num];
	for(int i = 0 ; i < num ; i++){
		cout<<"Enter the name of Event "<<i+1<<":";
		cin>>events[i].event_name;
		cout<<"Enter the date of the Event "<<i+1<<":";
		cin>>events[i].event_date;
		cout<<"Enter the venue of Event "<<i+1<<":";
		cin>>events[i].venue;
		cout<<"Enter the oragnizer of the Event "<<i+1<<":";
		cin>>events[i].organizer;
		cout<<endl;
	}

	char search_date[10];
	cout<<"Enter the date of the Event for search:";
	cin>>search_date;
	searching_date(events,search_date,num);
	delete []events;
	return 0;
}

void searching_date(struct Events *events ,char search_date[] , int num){
	int flag = 0 ;
	for(int i= 0 ; i < num ; i++){
		if(strcmp(events[i].event_date , search_date)==0){
			flag = 1;
		    cout<<"Event Name :"<<events[i].event_name<<endl;
		    cout<<"Event Date :"<<events[i].event_date<<endl;
		    cout<<"Event Venue :"<<events[i].venue<<endl;
		    cout<<"Event Organizer :"<<events[i].organizer<<endl;
		    cout<<endl;
        }
}
		if(flag == 0){
		cout<<"Event not found :)";
	}
}
