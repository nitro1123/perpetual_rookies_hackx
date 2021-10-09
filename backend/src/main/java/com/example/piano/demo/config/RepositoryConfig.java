package com.example.piano.demo.config;

import com.example.piano.demo.repository.Repository;
import org.springframework.beans.factory.annotation.Configurable;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class RepositoryConfig {

    @Bean
    public Repository getRepo() {
        return new Repository();
    }

}
