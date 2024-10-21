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


### Схемы подключения 
![Dazzling Jarv](https://github.com/user-attachments/assets/a05cde81-e87d-49dd-837e-4fb0c3ce826d)
![image](https://github.com/user-attachments/assets/9c24c18b-fe2a-4f2f-a6fd-9685373ebe3a)

### Видео работы проекта 
https://cloud.mail.ru/public/YsXo/9wuftQXbf


## Управление светодиодом в зависимости от освещенности с arduino nano [LedPhotoDistributedSerial](https://github.com/Kirilligu/Internet-of-Things/tree/main/LedPhotoDistributedSerial).
#### Этот проект реализует управление светодиодом в зависимости от показаний фоторезистора, используя две Arduino-платы. Одна плата контролирует светодиод, а другая считывает значения освещенности с фоторезистора и передает их на первую плату. Датчик и светодиод подключены к разным микроконтроллерам. Микроконтроллеры не связаны между собой напрямую, только с помощью USB через ПК. Микроконтроллеры просто отрабатывают команды присланные с ПК, решение принимается на ПК.

### Для создания понадобится:
- Плата Arduino (x2)
- Фоторезистор
- Светодиод
- 2 резистора 
- Макетная плата и соединительные провода

### Шаги по сборке проекта
1. Фоторезистор подключить к аналоговому пину A7 (если используете Arduino uno, то нужно поменять порт как на плате, так и в коде, например на A5)
2. Светодиод подключить к цифровому пину 2
3. Установите Arduino IDE на компьютер
4. Загрузите коды в платы через USB-кабель


### Схемы подключения 
![Smooth Waasa-Curcan](https://github.com/user-attachments/assets/4d917338-38a9-40ec-b54d-05e6c2c3fe18)
![image](https://github.com/user-attachments/assets/347defe8-8e0e-41ac-a229-b26cd36dafc3)


### Видео работы проекта 
https://cloud.mail.ru/public/NaiE/nyKNdCcHd


## Управление светодиодом на основе данных с датчика освещенности через MQTT [MQTT](https://github.com/Kirilligu/Internet-of-Things/tree/main/MQTT).
#### Этот проект реализует распределенное управление светодиодом на основе показаний освещенности, считываемых с датчика, используя два микроконтроллера и коммуникацию между ноутбуками через протокол MQTT. Один микроконтроллер считывает данные с фоторезистора, нормирует их и отправляет через MQTT, в то время как второй микроконтроллер управляет светодиодом на основе полученных данных.

### Для создания понадобится:
- Плата Arduino (x2)
- Фоторезистор
- Светодиод
- 2 резистора 
- Макетная плата и соединительные провода
- Ноутбуки (по одному на каждый микроконтроллер)
- Программы для подключения плат между собой

### Шаги по сборке проекта
1. Фоторезистор подключить к аналоговому пину A7 (если используете Arduino uno, то нужно поменять порт как на плате, так и в коде, например на A5)
2. Светодиод подключить к цифровому пину 2
3. Установите Arduino IDE на компьютер
4. Загрузите коды в платы через USB-кабель
5. Запустить программы с MQTT 


### Схемы подключения 
![Smooth Waasa-Curcan](https://github.com/user-attachments/assets/4d917338-38a9-40ec-b54d-05e6c2c3fe18)
![image](https://github.com/user-attachments/assets/347defe8-8e0e-41ac-a229-b26cd36dafc3)


### Видео работы проекта 
https://cloud.mail.ru/public/dcW4/RNegrKx3y
