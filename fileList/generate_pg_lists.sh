ls /bundle/data/T2K/users/gpenn/particle_gun/antimu/output/*anal*.root > particlegun_antimu.txt
ls /bundle/data/T2K/users/gpenn/particle_gun/proton/output/*anal*.root > particlegun_proton.txt
ls /bundle/data/T2K/users/gpenn/particle_gun/piplus/output/*anal*.root > particlegun_piplus.txt
ls /bundle/data/T2K/users/gpenn/particle_gun/positron/output/*anal*.root > particlegun_positron.txt
cat particlegun_antimu.txt particlegun_proton.txt particlegun_piplus.txt particlegun_positron.txt > particlegun_allpositive.root
