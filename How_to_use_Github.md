# How to use Github
1. Git Bash 설치 https://gitforwindows.org/
2. Repository 생성
3. <U>원하는 폴더</u> 오른쪽 클릭 -> Git Bash here 클릭
4. cmd같은 창 나오게 됨
5. git init 입력
6. .git 이라는 폴더가 <u>원하는 폴더</U> 안에 생성
7. git remote add origin >repository 주소입력<.git 입력함
8. 아무런 말이 뜨지 않으면 정상적으로 연결됨을 의미함
>git pull origin master = 지정해놓은 repository에서 해당폴더로 repository에 있는 모든 자료를 끌어오는 명령어
>
>* * *
>
>git status = 현재 나의 로컬폴더와 git과의 싱크상태를 설명해주는 명령어
>
>git add . = 로컬폴더와 git repository 사이의 어떠한 변경되 파일들이 있을때 모든 파일들을 트랙킹해달라는 명령어
>
>git commit -m "message" = 커밋을 다는 명령어임. 내가 다른이에게 알려주는 메세지를 적을 수 있는 명령어임
>
>git push origin + master = 실제로 git에 push

9. 올리고 싶은 파일( .md, .txt파일) 을 <U>원하는 폴더</U> 에 드래그앤드롭으로 넣어줌
10. git bash 로 돌아가 git status 입력하여 방금 넣어준 파일을 확인
11. git add . 입력
12. git commit -m "message" 입력: 명령어로 원하는 커밋 message안에 입력함
13. 성공적으로 commit한 후 실제로 git에 push를 해야 실제로 올라가게 된다.
14. ~~로그인 요청 창이 나옴(case by case): 아이디, 비밀번호 입력~~
15. git push origin master 입력
16. github 사이트에서 파일이 업로드된 것을 확인할 수 있다.

***
## 다른 사람 git 가져오기
1. 새로운 폴더 생성(다른 사람의 git을 저장할 폴더)
2. 오른쪽 클릭 -> git bash here
3. git init 입력
4. git remote add origin >타인의 repository 주소<
5. git pull origin master 입력
6. 파일을 받은 것을 확인 가능
***
## 파일 수정(변경)하는 방법
1. (시작 전에) 한번 연결한 폴더는 git init 과 git remote 가 완료된 상태이므로 입력 X
2. 수정하고싶은 파일을 수정한다.
3. git status 입력
4. modified 파일이름.md 이 빨간색 글자로 뜨는 것을 확인할 수 있음
5. git add . 입력
6. git commit -m "message" 입력: 명령어로 원하는 커밋 message안에 입력함
7. git push origin master 입력하여 업로드한다.
8. github 사이트에서 파일이 업로드된 것을 확인할 수 있다.
