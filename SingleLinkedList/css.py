
n = input("Enter number process: ")
n = int(n)
arr = [][6]

for i in range(n):
    x = print("Enter processID: " +str(i+1) + ": ")
    x.append(arr[i][0])
    y = print("Enter Arrival Time:")   
    y.append(arr[i][1])
    z = print("Enter Burst Time:")   
    z.append(arr[i][2]) 


print("\n----------------------------------------------------------\n")
print("Before Arrange\n")
print("Process ID\tArrival Time\tBurst Time\n")

for i in range(n):
    print(arr[i][0] + "\t" + arr[i][1] + "\t" + arr[i][2] + "\n")