package com.example.piano.demo.model;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.Setter;

import java.util.Date;

@Getter
@Setter
@AllArgsConstructor
public class Student {
    int id;
    String name;
    Date createdAt;
    int trainerId;
    Key key;
}
