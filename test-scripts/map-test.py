import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

def load_xy_data(file):
    df = pd.read_csv(file)
    return df

def plot_points_line(data):
    # Plot the data as a scatter plot
    plt.scatter(data['x'], data['y'], s=10, c='red')
    # Plot a line connecting the points
    plt.plot(data['x'], data['y'], linewidth=0.5)
    # Normalize the x and y axes to show a range from 0 to 100
    plt.xlim(0, 100)
    plt.ylim(0, 100)
    # Set the x and y ticks to show only intervals of 10
    plt.xticks(range(0, 101, 1))
    plt.yticks(range(0, 101, 1))
    # Add labels and title to the plot
    plt.xlabel('X')
    plt.ylabel('Y')
    plt.title('Data Plot')
    # Show the plot
    plt.show()

def plot_grid_map(data):
    # Create grid
    grid = np.zeros((100, 100))
    # Mark walls
    for _, row in data.iterrows():
        x, y = row['x'], row['y']
        grid[y, x] = 1  # mark wall as 1 (black)
    # Plot grid
    plt.imshow(grid, cmap='binary')
    # # Normalize the x and y axes to show a range from 0 to 100
    plt.xlim(0, 100)
    plt.ylim(0, 100)
    # Set the x and y ticks to show only intervals of 10
    plt.xticks(range(0, 101, 1))
    plt.yticks(range(0, 101, 1))
    # add a title and axis labels
    plt.title('Map')
    plt.xlabel('X')
    plt.ylabel('Y')
    plt.show()
    
plot_points_line(load_xy_data('test-scripts/data-test.csv'))