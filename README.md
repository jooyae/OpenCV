


## Computer Vision OpenCV 

:heavy_check_mark: OpenCV Projects 

 - Affine Transform 
	 - 어파인 변환은 영상의 이동, 전단, 확대, 회전을 조합할 때, 직사각형이 평행사변형으로 변화되는 원리 
	 - 어파인 변환을 표현하는 방법은 2X3 행렬의 실수형에 회전, 크기, 이동 정보가 포함 
	 - 어파인 변환은 미지수가 6개이기 때문에 6개의 식이 필요로 하며 점 3개가 어디로 이동했는지 알아야 행렬로 표시 가능 
	 - 점 세개의 이동정보를 알면 어파인 행렬로 표시가 가능하고 마지막 점의 위치를 예측, 추정 가능
	

 <img src="https://user-images.githubusercontent.com/58849278/121667762-95886e80-cae5-11eb-93e3-27fdeef8b443.png" width = 60%><img src="https://user-images.githubusercontent.com/58849278/121668217-0b8cd580-cae6-11eb-841d-d19664472f5b.png" width = 60%>

 - Perspective Transform 
	 - 어파인 변환보다 자유도가 높은 투시변환
	 - 직사각형보다 자유도가 높은 사다리꼴, 임의의 사각형으로 변환 가능 
	 - 투시변환은 3X3 행렬이며 하나는 비례상수 역할을 하기 때문에 실제 미지수는 8개 
	 - 8개의 미지수를 계산하기 위해 식 8개가 필요하며 점 4개가 어떻게 이동했는지 알아야 행렬 표시 가능 

<img src="https://user-images.githubusercontent.com/58849278/121668868-b1404480-cae6-11eb-83e1-209d4a70a2b7.png" width = 60%><img src="https://user-images.githubusercontent.com/58849278/121668926-c026f700-cae6-11eb-9048-b04911558250.png" width = 60%>

 - getAffineTransform 
	 
	 <img src="https://user-images.githubusercontent.com/58849278/121669152-fcf2ee00-cae6-11eb-8ef2-44a0807a3cb0.png" width=70%>

	
