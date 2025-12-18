def sort_colors(colors):
    
    n = len(colors)
    
    for i in range(n-1):
        for j in range(i+1, n):
            if colors[j]<colors[i]:
                colors[j], colors[i] = colors[i], colors[j]

    return colors