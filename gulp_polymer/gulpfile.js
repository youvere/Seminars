'use strict';

var gulp = require('gulp');
var sass = require('gulp-sass');
var browserSync = require('browser-sync');
var reload = browserSync.reload;

gulp.task('html', function () {
    gulp.src('./app/**/*.html').pipe(gulp.dest('./dist'));
});

gulp.task('scripts', function () {
    gulp.src('./app/scripts/**/*.js').pipe(gulp.dest('./dist/scripts'));
});

gulp.task('styles', function () {
    gulp.src('./app/styles/**/*.scss').pipe(sass()).pipe(gulp.dest('./dist/styles'));
});

gulp.task('images', function () {
    gulp.src('./app/images/**/*').pipe(gulp.dest('./dist/images'));
});

gulp.task('copy', function () {
    gulp.src('bower_components/**/*').pipe(gulp.dest('dist/bower_components'));
});

gulp.task('serve', ['copy', 'html', 'scripts', 'styles', 'images'], function () {
    browserSync({
        server: {
            baseDir: './dist'
        }
    });

    gulp.watch('./app/**/*.html', ['html', reload]);
    gulp.watch('./app/scripts/**/*.js', ['scripts', reload]);
    gulp.watch('./app/styles/**/*.scss', ['styles', reload]);
    gulp.watch('./app/images/**/*', ['images', reload]);
});
