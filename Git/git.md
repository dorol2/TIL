- git branch 원하는 브랜치 이름 : 브랜치 생성
              만들때는 feature/

- git branch -v : 브랜치 목록 보기
- git checkout 브랜치 이름 : 이쪽 브랜치로 이동
- git checkout 파일 이름 : 해당 파일 롤백
- git push origin 브랜치 이름
- git pull origin 브랜치 이름
- git merge 받아오길 원하는 브랜치 이름 : (브랜치에 있는 정보를 지금 현재 브랜치로 가져오는 것)
- git branch -d feature/birthday_clock : 지울때
- git reset HEAD 파일명 : git add 취소
-------------------------------------------------------------
< issues >
- 기능 	 : 브랜치 	: merge request 이름
- 기능추가 : feature/#23  : resolved #23
- 버그수정 : hotfix/#24   : hotfix #24
- 수정처리 : refs/#25	: refs # 25

----------------------------------------------------
- 이전 커밋으로 돌아가기 : git reset HEAD~1 --hard
- 되돌리기 참고 : https://88240.tistory.com/284

- 버그 고칠때 git branch hotfix/timer

- git commit --amend : author 바꾸기

- git rebase -i HEAD~2 : 숫자는 커밋갯수
	- i : insert
	- :wq

- git push --force origin 브랜치이름

- git branch -m <newname> : 브랜치이름 바꾸기

------------------------------------
< author 바꾸기 >

- git rebase -i HEAD~1
  	- i : insert -> pick을 e로 변경 -> esc키
	- : wq
	
- git commit --amend --author "dorol2 <dorol2@naver.com>"
- git rebase --continue

------------------------------------
