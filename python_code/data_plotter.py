from itertools import count
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

plt.style.use('Solarize_Light2')

index = count()

def animate(i):
    data = pd.read_csv('sensor_data.csv')
    x_vals = data['Index']
    y_vals = data['Distance']
    
    plt.cla()

    plt.plot(x_vals, y_vals, color="red")
    plt.ylabel("Distance from sensor (cm)")
    plt.xlabel("Time (sec)")
    plt.tight_layout()

ani = FuncAnimation(plt.gcf(), animate, interval=1000)

plt.tight_layout()
plt.show()