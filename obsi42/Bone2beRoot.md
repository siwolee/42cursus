# Introduction

set up own operating system while implementing ==strict rules.==

# Mandatory
	- Virtualbox 사용
	- signiture.txt file이 최상위 폴더에 있어야 함. 파일에는 가상머신의 가상 디스크 서명을 포함.
	- 데비안 또는 록키 추천(당신이 시스템 뉴비라면 데비안)
	- LVM을 사용하여, 최소한 두개의 encrypted partitions를 만들어라!
	- ssh 서비스 - 4242 포트만을 이용. 보안상 문제 때문에, root를 연결하는 건 금지
		- 몇 가지의 계정을 만들어서 테스트.
	- UFW 방화벽을 사용해서 운영체제를 만들어야 하며 4242 포트만 남겨둬야 함.
	- hostname : your login+42 : 평가 중 변경하게 될 것임.
	- 강력한 비밀번호 규정
		- 30일마다 expire
		- 바꾸고 나서 2일 이내에는 못바꿈
		- 
	- You have to install and configure sudo following strict rules.


https://techdebt.tistory.com/18러 
첫 설치 및 설정 방법. 

# 명령어
==lsblk== list block devices (파티션 나눠진 모습 보기)
==sudo== 
	`visudo` sudoers file 보기
`su -` super 유저로 로그인(root)



## USER
비밀번호 규정 (기간) `/etc/login.defs`
비밀번호 규정 (규칙) `/etc/pam.d/common-password`
	PAM 패키지 Pluggable Authentication Module 사용자 로그인 제어