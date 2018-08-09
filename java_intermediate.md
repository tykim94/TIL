# Object와 오버라이딩

Object클래스 = 모든 클래스의 최상위 클래스

아무것도 상속받지 않으면 자동으로 Object클래스 상속받음

Object클래스의 3가지 메소드
1. equals : 객체가 가진 값을 비교할 때 사용
2. toString : 객체가 가지고 있는 값을 문자열로 바꾸어서 return할 때 사용
3. hashCode : 객체의 해시코드 값 반환

equals와 hashcode를 사용하려면 오버라이딩을 해주는 것이 중요하다. 굉장히 자주 사용되는 개념이라서 이클립스에서 제공해주는 기능이다.
> 상단 메뉴바 -> source -> generate hashCode() and equals() -> 값 조정

toString도 똑같이 사용 가능하다.
> 상단 메뉴바 -> source -> generate toString() -> 값 조정
- - -
# java.lang 패키지/오토박싱

java.lang 패키지는 따로 임포트하지 않아도 자동으로 사용 가능하다.

java.lang 패키지에는 기본형 타입을 객체 타입으로 변환시킬때 사용하는 **Wrapper** 클래스가 있다.
>Boolean, Byte, Short, Integer, Long, Float, Double 클래스

__Object클래스__ 도 java.lang패키지 내에 있다. 또한 문자열과 관련된 __String, StringBuffer, StringBuilder__ , 화면 값 출력에 사용한 __System, math클래스, thread와 관련된 클래스들__ 모두 java.lang에 속해있다.
```java
public class WrapperExam {

	public static void main(String[] args) {
		int i = 5;
		Integer i2 = new Integer(5);//JAVA 9부터 deprecated된 클래스임

		Integer i3 = 5; //오토박싱

		int i4 = i3.intValue();//JAVA 5 이전 사용법

		int i5 = i3; //오토언박싱, JAVA 5 이후 사용법
	}
}
```
- 오토박싱 : 기본 타입 데이터를 객체 타입의 데이터로 자동 형변환 시켜주는 기능
- 오토언박싱 : 오토박싱의 반대 개념. 객체타입의 데이터를 기본형으로 자동 형변환
- - -
# 스트링버퍼(StringBuffer)
>String클래스 : 자기 자신이 변하지 않는 불변클래스
>
>StringBuffer클래스 : 자기 자신이 변하는 클래스

StringBuffer클래스의 대부분 메소드들은 자기 자신 this를 반환하는 모습을 가지고 있다.

```java
String str2 = new StringBuffer().append("hello ").append("world").toString();
	System.out.println(str2);
```
StringBuffer클래스는 자기 자신을 반환하므로 메소드 체이닝이 가능하다.
>메소드 체이닝(method chaining) : 자기자신을 리턴하여 계속해서 자신의 메소드를 호출하는 방법

따라서 우린 ```append().append().append().toString();``` 처럼 이을 수 있다.
- - -
# 스트링 클래스의 문제점

```java
public class StringExam2 {
	public static void main(String[] args) {
    //1. 반복적인 +연산 사용 (new 사용)
		String str1 = "";
		for(int i = 0 ; i < 100 ; i++) {
			str1 = str1 + "*";
		}
		System.out.println(str1);


    //2. StringBuffer의 체이닝메서드 사용
		StringBuffer sb = new StringBuffer();
		for(int i = 0 ; i < 100 ; i++) {
			sb.append("*");
		}
		String str2 = sb.toString();
		System.out.println(str2);
	}
}
```
문자열에 문자열을 더하는 식은 ```str + str```라고 적는데, 사실 +연산은 StringBuffer클래스의 append메소드를 이용하여 문자열이 누적되고, 그 누적이 끝난 문자열을 toString()을 통하여 String객체로 바꿔주는 연산이다.

따라서 반복문 내에서 + 연산을 진행하면 new연산을 반복하게되고, 프로그램 속도가 느려지므로 지양해야한다.

해결책으로는, StringBuffer의 체이닝메서드를 이용하면 new연산을 하지 않게되어 속도가 훨씬 빨라진다.
- - -
# Math클래스
>코싸인, 싸인, 탄젠트, 절대값, 랜덤값을 구할 수 있는 클래스

- Math클래스는 생성자가 private으로 되어 있기 때문에 new 연산자를 이용하여 객체를 생성할 수 없다.
- 객체를 생성할 수는 없지만 모든 메소드와 속성이 static으로 정의되어 있기 때문에 객체를 생성하지 않고도 사용할 수 있다.

모든 메소드가 static으로 설정되어있기 때문에 ```클래스명.메소드명```으로 사용한다.

```java
Math.max(v1, v2) : v1과 v2중 큰 값 리턴
Math.min(v1, v2) : v1과 v2중 작은 값 리턴
Math.abs(v1) : v1의 절대값 리턴
Math.random() : 0 ~ 1 사이에 double값 리턴
Math.sqrt(v1) : v1의 제곱근 리턴
Math.pow(v1, v2) : v1의 v2승
Math.log10(v1) : 로그 10의 v1 (  ex> log10(100) = 2  )
```
- - -
# java.util 패키지

java.lang 패키지 다음으로 많이쓰는 java.util 패키지이다.

날짜와 관련된 **date, calender 클래스** , 자료구조와 관련된 **collection framework클래스** 유용한 클래스를 많이 가지고 있음

>deprecated란? "더이상 지원하지 않으니 사용하지 않는 것이 좋다"의 의미
- - -
# Collection Framework

자료를 다룰 수 있는 자료구조 클래스

collection framework에서 가장 기본이 되는 인터페이스는 collection interface이다.

1. Collection interface는 여기에 자료가 있다는 것을 표현함. 중복도 허용하며, 자료가 저장되는 순서는 기억 못함. collection interface가 가지는 대표적인 메소드는 add(), size(), iterator()이다.

2. Iterator interface는 자료를 하나씩 꺼낼 수 있음. 가지는 메소드는 hasNext(), next()를 가진다.

3. Set interface는 중복을 허용하지 않는 자료구조를 표현한 인터페이스입니다. collection interface를 상속받고 있으며 가지는 메소드는 add()가 있다.

4. List interface는 collection interface를 상속받고 있다. 자료를 꺼내주는 get() 메서드를 가진다.

5. Map interface는 key 와 value를 가지며 put() 메서드를 이용하여 함께 저장합니다. 꺼낼때는 key를 이용한 get()메서드를 이용한다.
- - -
# 
