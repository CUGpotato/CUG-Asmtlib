
public class Member {

	private int id;
	private String name;
	
	Member(){
		id=0;
		name="";	
	}
	
	Member(int id,String name){
		this.id=id;
		this.name=name;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}
}
