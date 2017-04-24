import java.util.ArrayList;
import java.util.Scanner;

public class JosephCircle {
	 
	private int num;	//����
	private ArrayList<Member> members=new ArrayList<Member>();	//��Ա����
	private int start;			//��ʼ�ı��
	private int value;			//ÿ�εı���
	Scanner sc=new Scanner(System.in);
	
	JosephCircle(){
		start=0;
		value=0;
		System.out.println("��������Ҹ���:");
		num=sc.nextInt();
	};
		
	public void inputMember(){
		for(int i=0;i<num;i++){
			System.out.println("�������"+String.valueOf(i+1)+"λ��ҵ�������");
			String name=sc.nextLine();
			while(name.equals("")){
				name=sc.nextLine();
			}
			members.add(new Member(i+1,name));
		}
	}
	
	public void inputStart() {
		System.out.println("������ʼ��ұ�ţ���");
		start=sc.nextInt();
	}

	public void inputValue() {
		System.out.println("�����뱨����С��");
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
			del=(k+value-1)%members.size();	//ÿһ�ֱ�ɾ������
			if(del==0){
				del=members.size();
			}
			if(members.size()>1){
				System.out.println("���ֱ�ɾ���ı�ţ�"+members.get(del-1).getId());
				members.remove(del-1);				
				System.out.println("ʣ�µ�������"+members.size());
			}else{
				System.out.println("���ʤ������ұ�ţ�"+members.get(del-1).getId());
				System.out.println("���ʤ�������������"+members.get(del-1).getName());
				members.remove(del-1);	
			}					
			k=del;
		}
		
	}
}
