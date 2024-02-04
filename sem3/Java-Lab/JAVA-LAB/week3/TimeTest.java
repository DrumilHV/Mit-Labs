import java.util.Scanner;
class Time{
	int hours;
	int mins;
	int sec;
	int day;
	Time(){
		hours = 0;
		mins = 0;
		sec = 0;
		day = 0;
	}
	Time assigneTime(int hours,int mins, int sec, Time time){
		this.hours = hours;
		this.mins = mins;
		this.sec = sec;
		this.day = 0;

	return time;
	}
	Time addTime(Time time1, Time time2, Time timeResult){
		timeResult.hours = time1.hours + time2.hours;
		timeResult.mins = time1.mins + time2.mins;
		timeResult.sec = time1.sec+ time2.sec;

		do{

			if(timeResult.sec >= 60){
				timeResult.sec = timeResult.sec - 60;
				timeResult.mins += 1;
			}
			if(timeResult.mins >= 60){
				timeResult.mins = timeResult.mins - 60;
				timeResult.hours += 1;
			}
			if(timeResult.hours >=24){
				timeResult.hours = timeResult.hours - 24;
				this.day++;
			}
		}while(timeResult.hours>24 || timeResult.hours>=60 || timeResult.sec>= 60);
		return timeResult;
	}
	Time substractTime(Time time1,Time time2, Time timeResult){
		timeResult.sec = time1.sec - time2.sec;
		timeResult.mins = time1.mins - time2.mins;
		timeResult.hours = time1.hours - time2.hours;
		do{

		if(timeResult.sec<0){
			timeResult.sec+=60;
			timeResult.mins--;
		}
		if(timeResult.mins<0){
			timeResult.mins +=60;
			timeResult.hours-=1;
		}
		if(timeResult.hours<0){
			timeResult.hours += 24;
			this.day--;
		}
			return timeResult;
		}while(this.hours<24||this.mins<60||this.sec<60);
	} 
	void displayTime(Time time){
		if(time.day == 0){
			System.out.println(time.hours+":"+time.mins+":"+time.sec);
		}else if (time.day<0) {
			System.out.println(time.hours+":"+time.mins+":"+time.sec+" of "+ time.day+" days before.");
		}else if (time.day>0) {
			System.out.println(time.hours+":"+time.mins+":"+time.sec+" of "+ time.day+" days after.");
		}
	}
	boolean compairTime(Time time1 ,Time time2){
		boolean isEqual = true;
		if(time1.hours!=time2.hours || time1.mins!=time2.mins || time1.sec != time2.sec){
			isEqual =false;
		}
		return isEqual;
	}
}
class timeDemo{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Time time1 = new Time();
		Time time2 = new Time();
		Time timeResult = new Time();
		System.out.println("enter time in hh:mm:ss for time 1 ");
		time1.hours = sc.nextInt();
		time1.mins = sc.nextInt();
		time1.sec = sc.nextInt();
		System.out.println("enter time in hh:mm:ss for time 2 ");
		time2.hours = sc.nextInt();
		time2.mins = sc.nextInt();
		time2.sec = sc.nextInt();
		int ch = 'y';
		while(ch == 'y'){
		System.out.print("enter your choise:\nadd Time(1)\nsubstracte time(2)\ncompair time(3)");
		ch = sc.nextInt();
			switch(ch){
				case 1:
					timeResult = timeResult.addTime(time1,time2,timeResult);
					timeResult.displayTime(timeResult);
					break;
				case 2: 
					timeResult = timeResult.addTime(time1,time2,timeResult);
					timeResult = timeResult.substractTime(time1, time2, timeResult);
					timeResult.displayTime(timeResult);
					break;
				case 3: 
					if(time1.compairTime(time1, time2)){
						System.out.println(" time 1 and time 2 are equal");
					} else {
						System.out.println(" time 1 and time 2 are not equal");
					}
			}
			System.out.println("do you want to continue (y/n)?");
			ch = sc.next().charAt(0);
		}

	}
}
