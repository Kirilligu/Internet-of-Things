# Internet-of-Things

## Светофор с arduino nano [traffic lights](https://github.com/Kirilligu/Internet-of-Things/tree/main/traffic%20lights).
#### Проект представляет собой симуляцию работы светофора, управляемого микроконтроллером Arduino nano. Светофор может работать в двух режимах: автоматическом и ручном. В автоматическом режиме он циклически переключает цвета: зеленый (10 с) - мигающий зеленый (2 с) - желтый (1с) - красный (7 с) - желтый (1с) - зеленый (10 с). В ручном режиме можно управлять светофором через командную строку с ПК, задавая включение красного или зеленого света. Перед переключением между цветами через команды происходит 3-секундный переход через желтый цвет. После 60 секунд работы в ручном режиме светофор автоматически возвращается в автоматический режим.
### Для создания светофора понадобится:
- Плата Arduino
- Светодиоды (красный, жёлтый, зелёный)
- Резисторы от 165 Ом (3 шт)
- Соединительные провода
- Макетная плата (Breadboard)
- Компьютер с установленной Arduino IDE
- USB-кабель для подключения Arduino к компьютеру

### Шаги по сборке проекта
1. Подключите светодиоды к плате Arduino через резисторы
2. Подключите светодиоды к соответствующим пинам:
   - Красный — к пину 2
   - Желтый — к пину 3
   - Зеленый — к пину 4
3. Подключите общий провод всех светодиодов к GND на плате Arduino
4. Установите Arduino IDE на компьютер
5. Загрузите код в плату через USB-кабель
6. Откройте Serial Monitor для управления светофором

### Схемы подключения 
![scheme](https://github.com/user-attachments/assets/6e17c10e-c4ff-4f94-a171-aa6da2def8be)
![image](https://github.com/user-attachments/assets/dbd85289-1b3d-4aae-bf41-abf549f75320)

### Видео работы проекта 
https://cloud.mail.ru/public/vg27/Kyrp9uv6E

## Детектор источника света с arduino nano [Light_source_detector](https://github.com/Kirilligu/Internet-of-Things/tree/main/Light_source_detector).
#### Проект представляет собой детектор направления источника освещенности, который использует два фоторезистора для определения разницы в освещенности и индикации направления, в котором находится более яркий источник света (например, окно). Система управляет двумя светодиодами, которые сигнализируют, в какую сторону необходимо повернуть устройство, чтобы источник света оказался прямо перед ним. Когда устройство находится в оптимальном положении, оба светодиода горят постоянно.

### Для создания детектора источника света понадобится:
- Плата Arduino
- 2 фоторезистора
- 2 светодиода
- 2 резистора для светодиодов (4 шт)
- Макетная плата и соединительные провода

### Шаги по сборке проекта
1. Фоторезистор 1 (pht1) подключить к аналоговому пину A0
2. pht2 подключить к аналоговому пину A1
3. LED1 подключить к цифровому пину 9
4. LED2 подключить к цифровому пину 8
5. Установите Arduino IDE на компьютер
6. Загрузите код в плату через USB-кабель
7. Откройте Serial Monitor для управления светофором


### Схемы подключения 
![Dazzling Jarv](https://github.com/user-attachments/assets/a05cde81-e87d-49dd-837e-4fb0c3ce826d)
![image](https://github.com/user-attachments/assets/9c24c18b-fe2a-4f2f-a6fd-9685373ebe3a)

### Видео работы проекта 
https://cloud.mail.ru/public/YsXo/9wuftQXbf
