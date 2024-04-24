from django.shortcuts import render

# Create your views here.
from datetime import datetime
from django.http import HttpResponseRedirect
from .models import BlogPost, BlogPostForm

def achieve(request):
    posts = BlogPost.objects.all()[:10]
    return render(request,'achieve.html' ,{'posts':posts, 'form': BlogPostForm()})

def createblog(request):
    if(request.method == 'POST'):
        form = BlogPostForm(request.POST)
        if(form.is_valid()):
            post = form.save(commit=False)
            post.timestamp = datetime.now()
            post.save()
        return HttpResponseRedirect('/achieve/')
    return HttpResponseRedirect('/error/')


