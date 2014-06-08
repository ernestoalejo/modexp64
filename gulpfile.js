
var gulp = require('gulp'),
    gutil = require('gulp-util'),
    nodeunit = require('gulp-nodeunit');


gulp.task('default', function() {
  gutil.log(gutil.colors.red('Available tasks: test'));
});


gulp.task('test', function() {
  return gulp.src('test/*.js')
    .pipe(nodeunit());
});
