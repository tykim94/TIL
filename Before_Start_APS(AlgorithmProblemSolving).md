# C++ 그리고 [헤더 파일]

이때까지 프로그램을 짤 때, 함수는 몇 개 사용하지 않았다. 따라서 `main.cpp`에 함수의 선언부터 정의까지 모두 모아서 사용했었다. 하지만 실제 프로그래밍을 할 때에는 수많은 함수를 만들게 된다. `main.cpp`에 함수의 선언, 정의를 때려 붓는 행위는 가독성을 해치게 된다. 그리고 궁극적으로 알고리즘 문제 해결에 있어서 제시하는 cpp파일이 `main.cpp`이 아닌 `solution.cpp`이다. VisualStudio에서 실행해보고 결과를 제출해야 하는데, `main.cpp`과 `solution.cpp`를 동시에 돌리는 데에서 문제가 발생했다.

main함수에서 solution파일에서 만든 함수를 사용하고 싶은데 두 개의 cpp파일은 서로 독립적으로 컴파일이 되기 때문에, main함수에서 solution에서 만든 함수를 사용하고 싶지만 불가능하다. 따라서 선언을 해줘야 하는데 이 때 사용하는 것이 `<헤더 파일> < .h>`이다.

### 1. `#include <>` 와 `#include ""` 의 차이

>우리는 전처리기 사용에 있어서 #include 라는 지시자를 사용한다. 그 중 `<>`의 사용과 `""`의 사용에 대해 알아보겠다.

1. #include <filename>

 - 컴파일러와 함께 제공되는 헤더 파일을 include 할 때 사용한다. 대표적인 예로 `#include <iostream>`이 존재한다.

2. #include "filename"

 - 소스 파일이 있는 디렉터리에서 헤더 파일을 include 하도록 전처리기에게 지시한다. 대표적인 예로 `#include "solution.h"`이 존재한다.

- - -

# C++ 그리고 [헤더 파일 없이 컴파일]

>위 처럼 만들게 되면 `main.cpp`, `solution.h`, `solution.cpp` 세 개의 파일이 만들어진다. 더 간단하게 구현하기 위해 헤더 파일 없이 구현하는 법이 없을까?

### `main.cpp`에 solution함수 선언, `solution.cpp`에 solution함수 정의

```c++
#include <iostream>
#include <string>
#include <vector>
#include <queue>

//#include "solution.h"
using namespace std;

int solution(vector<int> priorities, int location); //solution함수 선언

int main()
{

	int a = solution({ 2,1,3,2 }, 2);
	cout << a << endl;

    return 0;
}
```
위는 `main.cpp`이다.

```c++
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) //solution함수 정의
{
	int answer = 0;
	return answer;
}
```
위는 `solution.cpp`이다.

보이는 대로 `main.cpp`에 선언, `solution.cpp`에 정의를 적으면 정상적으로 컴파일이 진행된다.
