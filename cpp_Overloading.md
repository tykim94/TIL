# 연산자 오버로딩

오버로딩은 함수의 이름은 같지만 받는 인수(매개변수)의 갯수나 종류가 다를 때, 구분하여 함수를 부를 수 있는 장치를 말한다. 그렇다면 연산자 오버로딩은? 연산자를 이용한 오버로딩된 함수라는것을 예측할 수 있다!

```c++
int main(void)
{
  int a = 2;
  int b = 3;
  int c = a + b;
}
```
>우리는 저 덧셈 연산을 봤을때 자연스럽게 a와 b의 합이 c에 더해질 것이란걸 안다.
>
>그렇다면 이것은?


```c++
class Integer
{
private:
  int a;
public:
    //생략

};

int main(void)
{
  Integer A(3);
  Integer B(5);  //둘 다 멤버변수를 3과 5로 초기화시켜준다 가정
  Integer C = A + B;
}
```

클래스끼리 A + B 라는것은 존재하지 않는다. 하지만 우리가 눈으로 보기엔 당연한 계산이고 만일 저 계산이 가능하다면 개발자 입장에선 굉장히 편리할 것이다. 따라서 만들어진게 덧셈 연산 오버로딩이다.

우린 연산자 오버로딩에 있어서 가장 중요한것은 operator 이다. 기존 정수형끼리의 덧셈(int + int) 도 모두 이 operator를 통해서 만들어진다. 또한 이 operator 들이 오버로딩하여 실수형끼리의 덧셈(double + double) 도 가능하고 string끼리의 덧셈( str + str)도 가능하다.

```c++
class Point
{
private:
  int xpos, ypos;
public:
  Point(int x=0, int y=0) : xpos(x), ypos(y)
  { }
  Point operator+(const Point &ref)   //operator+라는 이름의 오버로딩된 함수
  {
    Point pos(xpos+ref.xpos, ypos+ref.ypos);
    return pos;
  }
};

int main(void)
{
  Point pos1(3, 4);
  Point pos2(10, 20);
  Point pos3 = pos1.operator+(pos2);  //이런 식으로 활용
}
```
위의 코드에서 보듯이 이런 식으로 operator+ 를 오버로딩하여, 기존에 정수형, 실수형, 문자열, 문자 밖에 못했던 덧셈 연산을, 개발자가 만든 클래스 덧셈연산으로 끌어들여왔다.

덧셈 연산뿐 아니라 뺄셈도 가능하고, 우리가 기존에 알던 +=, -=, ==, != 도 가능하고, ++, -- 를 활용한 전위증가, 후위증가 모두 가능하다.

심지어 cout의 <<, cin의 >>, endl 마저 operator<< 라든지, operator>> ㅓ이런 식으로 만들 수 있다. 이렇게 개발자가 원하는 기능을 집어넣는것은 순전히 개발자의 몫이다.


---
추가해야할 내용: 대입연산자, 디폴트복사생성자, 배열 연산자 오버로딩
