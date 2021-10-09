package com.example.piano.demo.controller;

import com.example.piano.demo.model.Student;
import com.example.piano.demo.repository.Repository;
import com.example.piano.demo.request.StudentReponse;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
public class StudentController {

    @Autowired
    private Repository repository;
    //Student CRUD
    @GetMapping("/students")
    public List<Student> getStudents() {
        return repository.getAllStudents();
    }

    @PostMapping("/students")
    Student createStudent(@RequestBody Student student){
        return repository.saveStudent(student);
    }

   /* @GetMapping("/students/{id}/keys/{keyid}")
    public boolean consumeKeyFromServer(@PathVariable int id, @PathVariable int keyid) {
        return repository.consumeKeyFromServer(id, keyid);
    }*/

    @GetMapping("/trainers/{id}/keys")
    public StudentReponse trainerPassKey(@PathVariable int id) {

        return new StudentReponse(repository.getKeyFromServer(id));
    }
}
