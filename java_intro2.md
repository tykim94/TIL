# 상속
- Truck __is a__ Car.
- Notebook is __kind of__ computer.

이와 같은 'is a', 'kind of'같은 문법을 ***상속*** 이라고 한다.
```java
public class Bus extends Car {

}
```
extends라는 것 뒤에 붙는 클래스가 넘겨주는 클래스이다. Bus is a Car 이라고 이해해도 좋다.

Bus클래스는 Car의 메서드를 상속받을 수 있다. 하지만 반대로 Car클래스는 Bus클래스의 메서드를 상속 받을 순 없다.

부모가 가지고 있는 메소드외에 추가로 메소드를 선언하는 것을 확장하였다고 표현한다.
- - -
# 접근 제한자
> 클래스 내에서 멤버의 접근을 제한하는 역할

캡슐화 : 남에게 알려도 괜찮은 정보가 있는가 하면, 가족에게만 알려주고싶은 정보도 있고, 나만 알고싶은 정보도 있다. **이러한 관련된 내용을 모아서 가지고 있는 것을 캡슐화라고 함.**

## 접근지정자 종류
- public : 어떤 클래스는 접근 가능
- protected :  같은 패키지인 경우 접근 허용. 하지만, 다른 패키지라도 상속을 받은 경우 접근을 허용
- private : 자기 자신만 접근
- default : 아무것도 쓰지 않은 경우. 자기 자신과 같은 패키지 내에서 접근 허용

접근지정자 : public > protected > default > private
- - -
# 추상클래스
>비둘기, 짜장면? 어떠한 이미지가 딱 떠오른다. 누구한테나 물어봐도 비슷한 그림을 상상할 수 있다. 하지만, 새, 음식? 어떤 이미지가 떠오를까. 뭔진 알겠는데 구체적인 구현은 모두 다르다.

이렇게 모호한 단어들을 가진 클래스들은 부모로서의 역할은 수행할 수 있지만, 객체로의 구현은 불가능하다. 객체가 될 수 있는 클래스는 구체적이어야만 한다.
```java
public abstract class Bird {

	public abstract void sing();

	public void fly() {
		System.out.println("날다");
	}
}
```

Bird라는 클래스에 abstract라는 단어가 붙여져있다. 추상적이라는 의미인데 클래스 내에 추상 메서드가 단 하나라도 존재한다면 클래스는 추상클래스로 바뀌어야한다. <u>위에서 sing메서드를 abstract시켰기 때문에 클래스도 abstract시킨 것을 확인할 수 있다.</u>

또한 추상클래스에서는 일반 클래스처럼 일반적인 메서드도 사용 가능하다. <u>위에서 fly메서드를 일반적인 메서드 형식으로 만든 것을 확인할 수 있다.</u>
```java
public class Duck extends Bird {

	@Override //선언만 시켜놓은 메서드 자동으로 튀어나옴
	public void sing() {
		System.out.println("꽥꽥");
	}
}
```
추상클래스를 부모로 이용한 Duck이라는 자식 클래스를 확인할 수 있다. 추상클래스에서 만들어준 추상 메서드는 자식에서 한번 더 작성해줘야 한다.
```java
public class DuckExam {
	public static void main(String[] args) {
		Duck duck = new Duck();
		duck.sing();
		duck.fly();

		//Bird b = new Bird(); //컴파일 에러
	}
}
```
추상클래스를 상속받은 클래스의 객체 생성과 그 객체로서의 매서드 사용은 이때까지 해온 일반적인 사용법과 다르지 않다. 또한 추상클래스를 이용한 객체 생성은 불가능하다.
- - -
# super와 부모생성자

- this : 나를 가리키는 키워드
- super : 부모를 기리키는 키워드

따라서 super();는 부모 생성자를 부르는 코드이다.
- - -
# 오버라이딩

- 부모가 가진 메서드와 똑같은 모양의 메서드를 자식이 가지고 있는 것을 이야기함
- 메서드를 재정의함
>Overriding : 올라타다

부모 클래스에도 run메소드를 정의하고, 자식 클래스에도 완벽히 똑같은 모양의 run메소드를 정의한다. 그 후 다른 클래스에서 자식 클래스를 이용하여 객체를 생성하고 run을 부르면 자식 클래스의 run만 부르게 된다. 부모가 만든 메소드 위에 자식 클래스가 그대로 올라타는 그림을 연상하자.

만일 부모 클래스의 run메소드를 부르고 싶다면, ```super.run();```이라고 적는다.
- - -
# 클래스 형변환
우리는 bus 가 car의 일종이라고 안다. bus가 자식클래스라면 car는 부모클래스이다. 우린 버스를 보고 "버스다" 라고 할 수도 있지만, "차다"라고도 할 수 있다.

버스객체를 Car 타입의 참조변수로 참조할 수 있다. 부모타입으로 자식객체를 참조하게되면 부모가 가지고잇는 메스드만 사용할 수 있다.

부모타입으로 자식을 가리킬 수 있다. 이 경우 부모가 가지고 있는 내용만 사용 가능함.

```java
public class Car {
	public void run() {
		System.out.println("car달려");
	}

  public void yoyo() {
    System.out.println("yoyo");
  }
}
```

```java
public class Truck extends Car {
	public void ppangppang() {
		System.out.println("빵빵");
	}
	public void run() {
		System.out.println("트럭run");
	}
}
```
Car은 부모, Truck은 자식이며 run이 오버라이딩 됨을 알 수 있다.

```java
public class TruckExam {

	public static void main(String[] args) {
		Car c = new Truck(); //부모가 자식을 가리킬 수 있다.
		c.run();
//	c.ppangppang();
    c.yoyo();

		Truck truck = (Truck)c; // c는 car타입인데? bus는 못받아요
		truck.run();
		truck.ppangppang();
	}
}
```

```Car c = new Truck();```에서 보이듯이 Truck형으로 만든 객체를 Car라는 참조 타입으로 받을 수 있다. 다른 말로는, 부모가 자식을 가리킬 수 있다.

부모타입으로 자식객체를 참조하게 되면 부모가 가지고 있는 메소드만 사용 가능하다. run은 부모와 자식 둘 다 가지고 있는 오버라이딩이므로 사용 가능하며, ppangppang은 자식만 가지고 있는 메소드이므로 사용할 수 없다. 부모만 가지고 있는 메소드인 yoyo도 사용 가능하다. __부모가 가진 메소드만이 사용 가능함을 알자.__ 물론 위에서 오버라이딩 된 run은 자식의 메소드가 실행된다.

객체들 끼리의 형변환이 가능한데, 단 상속관계에 있었을 때만 가능하다.

마지막으로 부모타입의 객체를 자식타입으로 참조하게 할때는 명시적으로 형변환 해주어 한다. 단 이렇게 형변환 할때에는 부모가 참조하는 인스턴스가 형변환 하려는 자식타입일 때만 가능하다. _말이 어려우니 코드로 설명하겠다._
```java
public static void main(String[] args) {
      Car c = new Truck();
      Truck truck = (Truck)c; //가능
```
위는 객체 생성 시, 자식클래스로 만들어진 객체를 부모클래스 타입으로 받았다. 이 때는 만들어진 인스턴스 c는 Truck으로 형변환 하는것이 가능하다.
```java
public static void main(String[] args) {
      Car car = new Car();
      //Truck truck = (Truck)car;  //컴파일 에러, 불가능
```
하지만 위의 코드는, 부모클래스로 만든 객체를 부모클래스 타입으로 받았다. 우리가 봤던 가장 일반적인 객체 생성이다. 이 때는 만들어진 인스턴스 car는 Truck으로 형변환하는것이 불가능하다.
- - -
# 인터페이스 만들기
__인터페이스__ = 서로 관계가 없는 물체들이 상호 작용을 하기 위해서 사용하는 장치나 시스템
```java
public interface TV {
	public int MIN_VOLUME = 0;
	public int MAX_VOLUME = 100;

	public void turnOn();
	public void turnOff();
	public void changeVolume(int volume);
	public void changeChannel(int channel);
}
```
이런 식으로 마치 함수의 선언만 하는 것처럼 작성한다. 또한 인터페이스에서 만든 변수는 상수처럼 사용 가능하다.
- - -
# 인터페이스 사용하기
```java
public class LedTV implements TV{
    public void on(){
        System.out.println("켜다");
    }
    public void off(){
        System.out.println("끄다");   
    }
    public void volume(int value){
        System.out.println(value + "로 볼륨조정하다.");  
    }
    public void channel(int number){
        System.out.println(number + "로 채널조정하다.");         
    }
}
```
implements라는 키워드를 이용함을 알 수 있다. 이클립스 툴을 이용하여 인터페이스를 이식하면, 세부구현을 제외한 모든 메소드는 복사 붙여넣기 됨을 확인할 수 있다.
- - -
# 인터페이스의 default method
인터페이스에서 default를 붙여 구현할 수 있다.
```java
default int exec(int i, int j) {
  return i + j;
}
```
기존의 인터페이스에서 선언한 메소드는 인터페이스를 이식해 만든 클래스에서 추가 구현해줘야 하는데, 이 default를 이용한 친구는 인터페이스 내에서 구현을 끝낸다. 사용법은 다른 일반적인 메소드들과 똑같이 구현한다.
```java
public static int exec2(int i, int j) {
	return i + j;
}
```
또한 인터페이스 내에서 static을 이용하여 default처럼 클래스에서 추가 구현할 필요없이 구현을 끝낼 수 있는데, default와 다른점이 있다면, 실제 사용시
```java
  cal.plus(3, 4);
  cal.exec(3, 4); //기존의 메소드 호출법

  Calculator.exec2(3, 4);//static메소드 호출법
```
기존의 메소드 호출시엔 ```인터페이스명.메소드명``` 이렇게 호출했다면, static메소드 호출법은 ```참조변수.메소드명``` 이런 식으로 호출한다.
- - -
# 내부클래스
>내부클래스 : 클래스 안에 선언된 클래스, 어느 위치에 선언되느냐에 따라 4가지 모양을 가지게 된다.

1. 중첩 클래스(인스턴스 클래스)
```java
public class InnerExam1 {
	class Cal{  //필드를 선언하는 위치에 클래스 생성
		int value = 0;
		public void plus() {
			value++;
		}
	}

	public static void main(String[] args) {
		InnerExam1 t = new InnerExam1();
    //내부의 Cal 클래스 사용하려면 우선 InnerExam1 생성해야함
		InnerExam1.Cal cal = t.new Cal();   //이런 식으로 참조변수 생성함
		cal.plus();
		System.out.println(cal.value);
	}
}
```
2. 정적 중첩 클래스(static 클래스)
```java
public class InnerExam2 {
	static class Cal{  //static으로 바뀜
		int value = 0;
		public void plus() {
			value++;
		}
	}

	public static void main(String[] args) {
		InnerExam2.Cal cal = new InnerExam2.Cal();
    //InnerExam2 를 따로 생성하지 않고 바로 참조변수 생성 가능
		cal.plus();
		System.out.println(cal.value);
	}
}
```
3. 지역 중첩 클래스(지역 클래스)
```java
public class InnerExam3 {
	public void exec() { //exec이라는 void메서드 안에 내부클래스가 있음
		class Cal{  
			int value = 0;
			public void plus() {
				value++;
			}
		}

		Cal cal = new Cal();
		cal.plus();
		System.out.println(cal.value);
	}

	public static void main(String[] args) {
		InnerExam3 t = new InnerExam3();
		t.exec();
	}
}
```
4. 익명 중첩 클래스
```java
public abstract class Action {
	 public abstract void exec();
}
```
추상 클래스를 하나 선언한다. 기존에는 추상 클래스를 이용하기 위해 하나의 클래스(여기선 MyClass.java)를 더 만들어서 참조변수 생성을 도왔다.
```java
Action action = new MyAction();
action.exec();
```
이런 식으로 생성을 도왔다. 하지만 여간 불편한게 아니다. 예를 들면, 한 번만 생성하면 되는 일이라서 한 번만 생성해 줄 건데 그 한 번을 위해 만드는게 귀찮다. 따라서 이때 익명 중첩 클래스를 사용하게 된다.
```java
Action action = new Action() {
			@Override
			public void exec() {
				System.out.println("exec");
			}
};
action.exec();
```
생성자 다음에 중괄호를 열고 닫음을 확인할 수 있다. 해당 생성자 이름에 해당하는 클래스를 상속받는 이름없는 객체를 만든다는 것을 뜻한다. 아까도 말햇듯이 __Action을 상속받는 클래스가 해당 클래스에서만 사용되고 다른 클래스에서는 사용되지 않는 경우에 이처럼 익명 중첩 클래스를 사용한다.__
- - -
# Exception

>만일 10/0 을 k라는 정수형 변수에 저장하라는 코드를 짠다 하자. 10 / 0이 말이 되는가? 따라서 불가능한 연산이라 java파일을 컴파일하면 불가능한 연산이라는 예외를 보여주며 컴파일을 종료시킨다.

이처럼 코드를 짤 때도 개발자가 예외처리를 하고싶은 구문이 있을 것이다. 그 예외처리는 아래처럼 진행한다.
```java
try{

}catch(예외클래스 변수명){

}finally{

}
```

- try : 수행할 코드, 예외 발생 가능성이 있는 블록
- catch : 예외 발생 시, 예외 처리할 블록
- finally : 예외 발생 여부에 상관없이 반드시 실행되는 블록, **생략 가능**

```java
///예시
public static void main(String[] args) {
		int i = 10;
		int j = 0;
		try {
			int k = i/j;
			System.out.println(k);
		}catch(ArithmeticException e) {
			System.out.println("0불가능"+e.toString());
		}finally {
			System.out.println("무조건실행");
		}
		System.out.println("main end");
	}
```

```java
///위 파일 컴파일 결과창
0불가능java.lang.ArithmeticException: / by zero
무조건실행
mainend
```
- - -
# Throws
throws는 예외가 발생했을때 예외를 호출한 쪽에서 처리하도록 던져준다.
```java
public class ExceptionExam {
	public static void main(String[] args) {
		int i = 10;
		int j = 0;
		try {
		int k = divide(i,j);
		System.out.println(k);
		}catch(ArithmeticException e){
			System.out.println(e.toString());
		}
	}

	public static int divide(int i, int j) throws ArithmeticException{
		int k = i/j;
		return k;
	}
}
```
이처럼 메서드 옆에 throw라는 키워드를 붙여서 메서드를 호출한 쪽에서 처리할 수 있도록 만들어준다.
- - -
# Exception 발생시키기
```java
public class ExceptionExam {
	public static void main(String[] args) {
		int i = 10;
		int j = 0;

		try {
		int k = divide(i,j);
		System.out.println(k);
		}catch(IllegalArgumentException e) {
			System.out.println(e.toString());
		}
	}

	public static int divide(int i, int j) throws IllegalArgumentException{
		if(j == 0) {
			throw new IllegalArgumentException("0으로 나눌 수 없습니다!");

		}
		int k = i/j;
		return k;
	}
}
```
j가 0일 경우에 new 연산자를 통하여 IllegalArgumentException 객체가 만들어 진다.

또한 throws가 아닌 **throw** 라는 점을 기억하자.
```java
///컴파일 결과
java.lang.IllegalArgumentException: 0으로 나눌 수 없습니다!
```
- - -
# 사용자 정의 Exception

사용자가 직접 예외 클래스를 정의해서 예외처리할 수도 있다.

사용자는 Exception 이나 RuntimeException을 상속받아서 새로운 exception클래스를 만들 수 있다. 굳이 사용자 정의 Exception을 만들 이유는 클래스 이름만 확인해도 개발자가 한눈에 들어올 수 있도록 하기 위해서이다.
- checked exception : Exception을 상속받은 클래스

 오류처리를 하지 않으면 컴파일 오류가 발생하기 때문에 반드시 오류를 처리해야하는 exception이다.
- unchecked exception : RuntimeException을 상속받은 클래스

 오류처리를 반드시 하지 않아도 컴파일 상에서는 오류를 발생시키진 않는다. 그런데 모든 예외상황에 대해서는 적절하게 예외를 처리해주는 것이 조금 더 안정적이게 수행될 것이다.


```java
public class BizException extends RuntimeException{
	public BizException(String msg) {
		super(msg);
	}
	public BizException(Exception ex) {
		super(ex);
	}
}
```

런타임 예외 클래스를 부모로 받아 만든 사용자 정의 Exception이다.
```java
public class BizService {
	public void bizMethod(int i) throws BizException{
		System.out.println("비지니스 메소드 시작");

		if(i<0)
			throw new BizException("매개변수 i는 0 이상이어야 합니다.");

		System.out.println("비지니스 메소드 종료");
	}
}
```
```java
public class BizExam {

	public static void main(String[] args) {
		BizService biz = new BizService();
		biz.bizMethod(5);
		try {
		biz.bizMethod(-3);
		}catch(Exception e) {
			e.printStackTrace();
		}
	}
}
```
사용자가 직접 만든 예외클래스라는 점을 제외하곤 사용법은 기존 예외처리와 똑같다.

# 자바 입문 끝
### 프로그래머스 '자바 입문' 강의를 듣고 작성했음을 알림
https://programmers.co.kr/learn/courses/5/
