# Algorithm

이곳에 업로드 되어 있는 pdf 및 각종 자료, 공지에 대한 출처는 [이곳](http://isa.hanyang.ac.kr/)에 있습니다.

### 강의 자료 관련 사항

- 모든 강의자료는 [Lecture_pdf](https://github.com/PineApple777/2016_2_2_study/tree/master/algorithm/Lecture_pdf)을 통해 확인 할 수 있습니다.
- 동일한 수업에 대한 온라인 강의는 다음과 같습니다. 오프라인 강의를 못들었을 경우 참고할 수 있습니다.
  - [ENG_Lecture](https://www.youtube.com/watch?v=6VbqrQXRr3A&index=1&list=PLSN_PltQeOyiJ2ns7y4LvZJaS5yiF_DSy)
  - [KOR_Lecture](https://www.youtube.com/watch?v=ScX2GklClQA&list=PLSN_PltQeOyhVHpyZusAtOietiPT0wYF7&index=9)

아래 내용은 알고리즘 코드 작성 및 컴파일 유의사항입니다. 이에 대한 내용은 [Algorithm과제](http://isa.hanyang.ac.kr:8080/) 페이지에서 가져온 것입니다. 

### 컴파일 관련 

- 기본적으로 리눅스 환경에서 g++을 이용하여 컴파일됩니다.
- 컴파일 옵션은 "**g++ -O2 -Wall -static -lm**" 이고, 사용된 g++의 버전은 4.4.3입니다.
- 결과로 Compile Error를 받으신 분들은 혹시나 c, cpp의 표준으로 작성했는지 확인바랍니다. void main()은 표준이 아닙니다. int main()으로 작성해주시고, exit code로 반드시 return 0을 해야합니다.
- scanf, printf 등의 입출력 관련 함수를 사용시, stdio.h를 include해주어야 합니다.
- 64비트 정수를 사용할 경우에는 long long을 이용하며, scanf/printf에서는 %lld를 이용하여 입출력을 수행합니다.
- 파일의 확장자가 소문자가 아닌 경우 컴파일을 하지 못할 수 있습니다.

### 주의사항

- 문제마다 제한 시간과 메모리 제한이 있습니다. 이를 확인하시고, 문제를 해결해주시길 바랍니다.
- 메모리 할당이나 문제 입출력을 위한 시스템 콜 이외에는 사용할 수 없습니다. 사용할 경우 해당 테스트 케이스에 대해 0점 처리됩니다. 사용할 수 없는 시스템 콜의 예는 시간 측정, 프로세스 복제, 다른 프로그램 수행 등이 있습니다.
- 결과보기의 메모리의 단위는 byte단위이며, 시간은 msec단위입니다. 시간은 모든 테스트 데이터에 걸린 시간을 합한 결과입니다.
