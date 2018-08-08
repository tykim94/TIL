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
		String str1 = "hello world";
		String str2 = str1.substring(5);
		System.out.println(str1);
		System.out.println(str2);

		String str3 = str1 + str2;
		System.out.println(str3);

		String str4 = new StringBuffer().append(str1).append(str2).toString();
		System.out.println(str4);

		String str5 = "";
		for(int i = 0 ; i < 100 ; i++) {
			str5 = str5 + "*";
		} //컴퓨터가new100번하게됨 -> java에서 프로그램의 속도가 느려짐->지양해야함
		System.out.println(str5);

		StringBuffer sb = new StringBuffer();
		for(int i = 0 ; i < 100 ; i++) {
			sb.append("*");
		}
		String str6 = sb.toString();
		System.out.println(str6);
	}
}
```
------세부사항 더 적어야해
