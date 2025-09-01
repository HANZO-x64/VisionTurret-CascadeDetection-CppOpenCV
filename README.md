# VisionTurret-CascadeDetection-CppOpenCV

ВВЕДЕНИЕ

Загружена на GitHub v1.3 - она одна из первых версий программы. Работает на 2 каскадных моделей + есть управление консолькой.
v1.0-1.2 не добавил.
v2.0 отключена.
Лучше всего перейти с каскадных моделей на нейросетевых (darknet/YOLO). 
Каскадные модели показали себя не эффективнее, так как в тени или в ярком освещении не детектит, но зато данный способ более компактной. 

КОНТРОЛЬ ВЕРСИЙ
1. Операционная система >> Windows 10
2. Среда разработки >> Visual Studio 2022 Community Edition >> https://visualstudio.microsoft.com/ru/vs/community/
3. Библиотека OpenCV >> opencv-4.12.0-windows >> https://github.com/opencv/opencv/releases/tag/4.12.0
4. Каскад для детекции лиц >> haarcascade_profileface.xml >> https://github.com/austinjoyal/haar-cascade-files/blob/master/haarcascade_profileface.xml
5. Каскад всего тело >> haarcascade_fullbody.xml >> https://github.com/opencv/opencv/blob/4.x/data/haarcascades/haarcascade_frontalface_default.xml
6. Альтернативный каскад с улучшенной точностью >> haarcascade_frontalface_alt.xml >> https://github.com/austinjoyal/haar-cascade-files/blob/master/haarcascade_frontalface_alt.xml
7. Оптимизированный каскад для детекции лиц >> haarcascade_frontalface_alt2.xml >> https://github.com/austinjoyal/haar-cascade-files/blob/master/haarcascade_frontalface_alt2.xml

КАЧЕСТВО КАСКАДОВ
1. haarcascade_profileface.xml & haarcascade_frontalface_alt.xml = 2/5
2. haarcascade_frontalface_alt.xml & haarcascade_frontalface_default.xml = 3.5/5
3. haarcascade_frontalface_alt2.xml & haarcascade_frontalface_default.xml = 3/5
4. haarcascade_profileface.xml & haarcascade_frontalface_default.xml = 2.5/5
5. haarcascade_profileface.xml & haarcascade_frontalface_alt2.xml = 1/5

КОМАНДЫ ДЛЯ КОНСОЛИ
1.	/start 
2.	/stop
3.	/info
4.	/help
5.	/setTarget
6.	/getTarget
7.	/setMode
8.	/getMode
9.	/setDelay
10.	/getDelay
11.	/setStartDelay
12.	/getStartDelay


ДАТЫ

0. 05.08.2025 — Начала разработки.
1. 10.08.2025 — V1.0
2. 12.08.2025 — V1.1
3. 13.08.2025 — Settings.V1
4. 15.08.2025 — V2
5. 16.08.2025 — V1.2
6. 18.08.2025 — V1.3
