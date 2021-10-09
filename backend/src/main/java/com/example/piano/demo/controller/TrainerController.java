package com.example.piano.demo.controller;

import com.example.piano.demo.model.Student;
import com.example.piano.demo.model.Trainer;
import com.example.piano.demo.repository.Repository;
import com.example.piano.demo.request.TrainerRequest;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
public class TrainerController {

    @Autowired
    private Repository repository;

    //Trainer CRUD
    @GetMapping("/trainers")
    public List<Trainer> getTrainers() {
        return repository.getAllTrainers();
    }
    @GetMapping("/trainers/{id}")
    public Trainer getTrainer(@PathVariable int id) {
        return repository.getTrainer(id);
    }
    @GetMapping("/trainers/{id}/students")
    public List<Student> students(@PathVariable int id) {
        return repository.students(id);
    }
    @PostMapping("/trainers")
    Trainer createTrainer(@RequestBody Trainer trainer) {
        return repository.saveTrainer(trainer);
    }

    //Trainer --> Keys    return keyid
   /* @GetMapping("/trainers/{id}/keys/{keynum}")
    public int trainerPassKey(@PathVariable int id, @PathVariable int keynum) {
        return repository.passKeytoServer(id, keynum);
    }*/

    @PostMapping("/trainers/{id}/keys")
    public boolean trainerPassKey(@PathVariable int id, @RequestBody TrainerRequest trainerRequest) {
//        return repository.passKeytoServer(id, keynum);
        return repository.passKeytoServer(id, trainerRequest);
    }






}
