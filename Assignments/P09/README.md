
## Assignment 5 - Run Times
#### Due: 03-02-2021 (Tuesday @ 12:30 p.m.)


-----

- Count = _____________________
  
- Complexity = ________________
  
```cpp
int count = 0;
int n = 1024;
for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++){
        count++;
    }
}
cout<<count<<endl;
```

-----

- Count = _____________________
  
- Complexity = ________________
  
```cpp
int count = 0;
int n = 1024;
for(int i = 0; i < n; i++) {
    for(int j = 0; j < i; j++){
        count++;
    }
}
cout<<count<<endl;
```

-----

- Count = _____________________
  
- Complexity = ________________
  
```cpp
int count = 0;
int n = 1024;
for(int i = 0; i < n; i++) {
    for(int j = 0; j < i; j++){
        for(int k = 0; k < n; k++){
            count++;
        }
    }
}
cout<<count<<endl;
```

-----

- Count = _____________________
  
- Complexity = ________________
  
```cpp
int count=0;
int n = 1024;
for(int i = 0; i < 2*n; i++) {
    count++;
}
cout<<count<<endl;
```

-----

- Count = _____________________
  
- Complexity = ________________
  
```cpp
int count=0;
int n = 1024;
for(int i = 0; i < n; i++) {
    for(int j = 0; j < 2n; j++){
        count++;
    }
}
cout<<count<<endl;
```

-----

- Count = _____________________
  
- Complexity = ________________
  
```cpp
int count=0;
int n = 1024;
for(int i = 0; i < n; i++) {
    count++;
}
for(int j = 0; j < n; j++){
    for(int k = 0; k < j; k++){
        count++;
    }
}
cout<<count<<endl;
