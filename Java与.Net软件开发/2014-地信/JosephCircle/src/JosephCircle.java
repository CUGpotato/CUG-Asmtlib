import java.util.ArrayList;
import java.util.Scanner;

public class JosephCircle {
	 
	private int num;	//人数
	private ArrayList<Member> members=new ArrayList<Member>();	//成员数组
	private int start;			//开始的编号
	private int value;			//每次的报数
	Scanner sc=new Scanner(System.in);
	
	JosephCircle(){
		start=0;
		value=0;
		System.out.println("请输入玩家个数:");
		num=sc.nextInt();
	};
		
	public void inputMember(){
		for(int i=0;i<num;i++){
			System.out.println("请输入第"+String.valueOf(i+1)+"位玩家的姓名：");
			String name=sc.nextLine();
			while(name.equals("")){
				name=sc.nextLine();
			}
			members.add(new Member(i+1,name));
		}
	}
	
	public void inputStart() {
		System.out.println("输入起始玩家编号：：");
		start=sc.nextInt();
	}

	public void inputValue() {
		System.out.println("请输入报数大小：");
		value=sc.nextInt();
	}

	public void Count(){
		while(start>num||start<=0){
			inputStart();
		}
		while(value<=0){
			inputValue();
		}
		int k=start;
		int del=0;
		while(members.size()>0){
			del=(k+value-1)%members.size();	//每一轮被删除的人
			if(del==0){
				del=members.size();
			}
			if(members.size()>1){
				System.out.println("此轮被删除的编号："+members.get(del-1).getId());
				members.remove(del-1);				
				System.out.println("剩下的人数："+members.size());
			}else{
				System.out.println("最后胜出的玩家编号："+members.get(del-1).getId());
				System.out.println("最后胜出的玩家姓名："+members.get(del-1).getName());
				members.remove(del-1);	
			}					
			k=del;
		}
		
	}
}
