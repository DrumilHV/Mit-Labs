from django.db import models

# Create your models here.

from django import forms

class BlogPost(models.Model):
    title = models.CharField(max_length=150)
    body = models.TextField()
    timestamp = models.DateTimeField()
    class Meta:
        ordering = ('-timestamp',)

class BlogPostForm(forms.ModelForm):
    class Meta:
        model = BlogPost
        exclude = ('timestamp',)

class PageModel(models.Model):
    index = models.PositiveIntegerField()
    category = models.CharField(max_length=100)
    title = models.CharField(max_length=100)
    url = models.URLField()
    views = models.PositiveIntegerField()
    class Meta:
        ordering = ('index',)

