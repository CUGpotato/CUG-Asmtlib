import Chairyfish.Example;
import Chairyfish.ExampleA;

public class BeanMain {

	public static void main(String[] args) {
		MyBeanFactory beanFactory = new MyBeanFactory();
		beanFactory.init("mybean.xml");
		Example exampleA = (Example) beanFactory.getBean("ExampleA");
		exampleA.doSomething();
		Example exampleB = (Example) beanFactory.getBean("ExampleB");
		exampleB.doSomething();
	}

}
