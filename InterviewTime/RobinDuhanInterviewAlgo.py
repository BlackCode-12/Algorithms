#!/usr/bin/env python
# coding: utf-8

# In[1]:


import pandas as pd
import numpy as np

#Taking the data as input
#Input the path of your csv file that must have a name column
data = pd.read_csv(input())
data.head()


# In[39]:


names = list(data["Name"])
names


# In[26]:


#the parameters needed for early finishing
#the starting time i.e 11:10 PM
#the ending time i.e 12:20 PM
#list of names
#Interview time
#the free-zone time

#24-hour clock
#12-hour clock
#variable interview time
#Using a priority queue will be helpful
#or just arrange the array

def earlyFinish(start_time, end_time, names, length_interview):
    timings = []
    final = []
    start_time = list(map(int, start_time.split(":")))
    s_t = start_time.copy()
    end_time = list(map(int, end_time.split(":")))
    e_t = end_time.copy()
    for i in range(len(names)):
        temp_length = length_interview
        a1 = names[i]
        if(int(start_time[1]) + temp_length > 59):
            start_time[0] = int(start_time[0]) + 1
            start_time[1] = int(start_time[1]) + temp_length - 60
            timings.append([start_time[0], start_time[1]])
        else:
            start_time[1] = int(start_time[1]) + temp_length
            start_time[0] = int(start_time[0])
            timings.append([start_time[0], start_time[1]])
        if(start_time > end_time):
            print("Not enough time for all the interviews")
            timings.pop()
            break
    
    b = str(s_t[0]) + ":" + str(s_t[1])
    for t in timings:
        a = b
        b = str(t[0]) + ":" + str(t[1])
        final.append([a,b])
    return final
    
    
    


# In[27]:


t = earlyFinish("9:00", "14:00", names, 30)
print(t)


# In[28]:


import numpy as np

#Starting time array
start_time_list = []
end_time_list = []
for i in t:
    start_time_list.append(i[0])
    end_time_list.append(i[1])



# In[35]:


data["Starting Time"] = np.array(start_time_list)
data["Ending Time"] = np.array(end_time_list)


# In[36]:


data.head()


# In[38]:


#Saving it for final use
data.to_csv("D://Interview Time.csv")


# In[ ]:




