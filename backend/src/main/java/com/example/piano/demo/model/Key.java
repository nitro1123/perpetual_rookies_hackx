package com.example.piano.demo.model;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.Setter;

import java.util.Date;

@Setter
@Getter
@AllArgsConstructor
public class Key {

    int id;
    int number;
    boolean isActive;
    int trainerid;
    Date createdAt;
}
