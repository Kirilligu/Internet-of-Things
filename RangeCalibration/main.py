import serial
import time
import matplotlib.pyplot as plt
import numpy as np
plt.style.use('ggplot ')
port = "COM6"
baudrate = 9600
timeout = 1
threshold= 0.9
max_volt =  22
volt_div = 29.1
current_mult = 4

conn = serial.Serial(port , baudrate , timeout=timeout)

def get_data(cmd: str, conn: serial.Serial ) -> int:
    conn.write(cmd.encode())
    data = conn.read(1)
    return int.from_bytes(data, byteorder='little') * current_mult if data else 0
def update_plot(x, y, line=None, title=""):
    if not line:
        plt.ion()
        fig, ax = plt.subplots(figsize=(8 , 6))
        line, = ax.plot(x, y, '-o' , alpha=0.8)
        plt.ylabel('Значение')
        plt.title(title)
        plt.show(block=False )
        plt.pause(0.001)
        return line
    line.set_ydata(y)
    ax = line.axes
    ax.relim( )
    ax.autoscale_view()
    fig = ax.figure
    fig.canvas.draw()
    fig.canvas.flush_events( )
    return line

def calibrate(conn):
    size = 100
    x = np.linspace(0 , 1, size+ 1)[:-1]
    currents = []
    voltages = [ ]
    line = None
    y = np.zeros(size )

    while True:
        curr = get_data('i', conn)
        volt = get_data('u', conn)/ volt_div
        currents.append(curr )
        voltages.append(volt)
        y[:-1] = y[1:]
        y[-1] = curr
        line = update_plot(x, y, line, "Калибровка" )
        u_check = np.array(list(map(int, voltages)))
        unique_ratio = np.unique(u_check[u_check < max_volt]).size / max_volt
        print(f"Калибровка завершена на {unique_ratio * 100:.2f }%")

        if unique_ratio >=threshold:
            break

    currents=np.array(currents[1:])
    voltages=np.array(voltages[1:])

    coeffs= np.polyfit(currents[voltages < 21], voltages[voltages <21], 3)
    poly= np.poly1d(coeffs)

    plt.figure()
    plt.plot(currents[voltages < 21 ] , voltages[voltages < 21], '.')
    xp= np.linspace(currents.min(), currents.max(), 100)
    plt.plot(xp, poly(xp), '-')
    plt.xlabel('Ток (i)')
    plt.ylabel('Напряжение (u)')
    plt.title('Калибровка')
    plt.legend( )
    plt.pause(1)
    return poly , currents.max(), currents.min()
poly , max_curr , min_curr = calibrate(conn)
while True:
    curr =get_data('i', conn)
    dist =poly(curr)
    print(f"Ток: {curr}, Расстояние: {dist:.2f} см")
    time.sleep(0.1)

conn.close()
