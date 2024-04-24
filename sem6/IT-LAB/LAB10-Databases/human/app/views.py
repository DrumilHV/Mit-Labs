from django.shortcuts import render, redirect
from .models import Human
from .forms import HumanForm

def index(request):
    humans = Human.objects.all()
    form = HumanForm()
    return render(request, 'index.html', {'humans': humans, 'form': form})

def update_human(request, human_id):
    human = Human.objects.get(pk=human_id)
    form = HumanForm(request.POST or None, instance=human)
    if form.is_valid():
        form.save()
        return redirect('index')
    return render(request, 'index.html', {'form': form})

def delete_human(request, human_id):
    human = Human.objects.get(pk=human_id)
    human.delete()
    return redirect('index')
