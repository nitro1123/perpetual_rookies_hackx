package com.example.piano.demo.repository;

import com.example.piano.demo.model.Key;
import com.example.piano.demo.model.Student;
import com.example.piano.demo.model.StudentKey;
import com.example.piano.demo.model.Trainer;
import com.example.piano.demo.request.TrainerRequest;
import org.springframework.context.annotation.Bean;
import org.springframework.web.bind.annotation.RequestBody;

import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.List;


public class Repository {
    int globalKey = 1;
    List<Trainer> trainerList;
    List<Student> studentList;
//    HashMap<Integer, Key> keyDB;
    HashMap<Integer, Integer> trainerToKeyDB;
    public Repository(){
        trainerList = new ArrayList<>();
        studentList = new ArrayList<>();
        trainerToKeyDB = new HashMap<>();
        createTrainer();
        createStudents();
    }
    public List<Trainer> getAllTrainers() {
        return trainerList;
    }
    public List<Student> getAllStudents() {
        return studentList;
    }
    public Trainer getTrainer(int id) {
        for(Trainer t: trainerList) {
            if(t.getId() == id)
                return t;
        }
        return null;
    }
    public Student getStudent(int id) {
        for(Student st: studentList) {
            if(st.getId() == id)
                return st;
        }
        return null;
    }

    public List<Student> students(int trainerid) {
        List<Student> students = new ArrayList<>();
        for(Student s : studentList) {
            if(s.getTrainerId() == trainerid)
                students.add(s);
        }
        return students;
    }
    public Trainer saveTrainer(Trainer trainer) {
        trainerList.add(trainer);
        return trainer;
    }

    public Student saveStudent(Student student) {
        studentList.add(student);
        return student;
    }

    /*public int passKeytoServer (int trainerid, int keynum){
       /Key key = new Key(globalKey++, keynum, true, trainerid, new Date());
        keyDB.put(key.getId(), key);
        return key.getId();

    }*/

    public boolean passKeytoServer(int trainerid, TrainerRequest trainerRequest) {
        trainerToKeyDB.put(trainerid, trainerRequest.getKeys());
        return true;
    }

    public int getKeyFromServer(int trainerid) {
        int key = 0;
        if(trainerToKeyDB.containsKey(trainerid))
            key = trainerToKeyDB.get(trainerid);
        return key;
    }

/*    public boolean consumeKeyFromServer(int studentid, int keyid) {
        Student student = getStudent(studentid);
        student.setKey(keyDB.get(keyid));
        return true;
    }*/

/*    public boolean processKey(int studentid){
        Student student = getStudent(studentid);
        Key studentKey = student.getKey();
        studentKey.setActive(false);
        return true;
    }*/

    public void createTrainer() {
        Date date = new java.util.Date();
        trainerList.add(new Trainer(101, "Vinayak", date));
        trainerList.add(new Trainer(102, "Chinmoye", date));
    }
    public void createStudents() {
        Date date = new java.util.Date();
        studentList.add(new Student(201, "Aditi", date, 101, null));
        studentList.add(new Student(202, "Preeti", date, 101, null));
    }
}
