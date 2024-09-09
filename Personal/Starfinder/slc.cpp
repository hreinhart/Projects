#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

struct spell
{   
    string name;
    string lvl;
    string school;
    string cast;
    string range;
    string area;
    string targets;
    string duration;
    string savingthrow;
    string resistances;
    string description;
    string briefdes;

spell(string name,string lvl, string sch, string cst, string rng, string area, string tgt, string dur, string sav, string res, string des, string bdes):
name(name), lvl(lvl), school(sch), cast(cst), range(rng), area(area), targets(tgt), duration(dur), savingthrow(sav), resistances(res), description(des), briefdes(bdes){};
};
void createmysticlist(){
    
}


int main(){
    //131
    spell mysticlist[] ={ spell("Daze", "0", "","","","","","","","","","Humanoid creature of CR 3 or lower is dazed."),
                        spell("Detect Affliction","0",,,,,,,,,,"Determine whether a creature or object has been poisoned, is diseased, is cursed, or is suffering a similar affliction"),
                        spell("Detect Magic","0",,,,,,,,,,"Detect spells and magic items withing 60 feet."),
                        spell("Fatigue","0",,,,,,,,,,"Touched creature is fatigued."),
                        spell("Ghost Sound","0",,,,,,,,,,"Create minor illusory sounds."),
                        spell("Grave Words","0",,,,,,,,,,"Force a corpse to babble."),
                        spell("Psychokinetic Hand","0",,,,,,,,,,"Telekinetically move an object of 1 bulk ot less."),
                        spell("Stabilize","0",,,,,,,,,,"Cause a dying creature to stabilize."),
                        spell("Telekinetic Projectile","0",,,,,,,,,,"Telekinetically hurl an object, dealing 1d6 damage to the target and object."),
                        spell("Telepathic Message","0",,,,,,,,,,"Send a short telepathic message and hear simple telepathic replies."),
                        spell("Token Spell","0",,,,,,,,,,"Perform simple magical effects."),
                        spell("Charm Person","1","Enchantment (charm, mind-affecting)","1 standard action","close (25ft +5 ft/2 levels)","N/A","One humanoid creature",
                        "1 day/level","Will negates","Yes","This charm makes a humanoid creature regard you as its trusted friend and ally (treat the target’s attitude as friendly). "
                        "If the creature is currently being threatened or attacked by you or your allies, however, it receives a +5 bonus to its saving throw.The spell does not enable "
                        "you to control the charmed creature as if it were an automaton. It is unlikely to attempt to harm you, but it is also unlikely to attack any of its true friends "
                        "or allies. You can try to give the target suggestions, but you must succeed at an opposed Charisma check to convince it to do anything it wouldn’t ordinarily "
                        "do. (Retries of this check are not allowed.) An affected creature never obeys suicidal or obviously harmful suggestions. Any act by you or your apparent allies "
                        "that threatens the charmed creature breaks the spell. You must speak the creature’s language to communicate your suggestions, or else be good at pantomiming","Make one humanoid creature believe that it is your ally."),
                        spell("Command","1","Enchantment (compulsion, language-dependent, mind-affecting)","1 standard action","close (25ft +5ft/2 levels)","N/A",
                        "One living creature","1 round","Will negates","Yes","You give the target one of the following commands, which it obeys to the best of its ability at its "
                        "earliest opportunity. If the target can’t carry out your command on its next turn, the spell automatically fails. Approach: The target moves toward you as "
                        "quickly and directly as possible for 1 round, taking no other actions and triggering reactions (such as attacks of opportunity) for this movement as normal. "
                        "Drop: The target drops whatever it is holding. It can’t pick up any dropped item until its next turn. Fall: The target falls to the ground and remains prone "
                        "for 1 round. It can otherwise act normally.Flee: The target moves away from you as quickly and directly as possible for 1 round, taking no other actions and "
                        "provoking reactions (such as attacks of opportunity) for this movement as normal. Halt: The target is dazed for 1 round.",
                        "One creature obeys a select command for 1 round."),
                        spell("Confusion, Lesser","1",,,,,,,,,,"One living creature is confused for 1 round."),
                        spell("Detect Radiation","1",,,,,,,,,,"Detect radiation within 120 feet."),
                        spell("Detect Thoughts","1",,,,,,,,,,"\"Listen\" to surface thoughts."),
                        spell("Disguise Self","1",,,,,,,,,,"Change your appearance."),
                        spell("Fear","1",,,,,,,,,,"Frighten a single living creature that's of CR 4 or lower for 1d4 rounds."),
                        spell("Identify","1",,,,,,,,,,"Gain a +10 bonus to identify items of a magic or technological nature."),
                        spell("Keen Senses","1",,,,,,,,,,"Target gains low-light vision and a +2 bonus to Perception checks."),
                        spell("Life Bubble","1",,,,,,,,,,"Encase targeted creatures with a shell of tolerable atmosphere."),
                        spell("Mind Link","1",,,,,,,,,,"Instantly and telepathically communicate information to a creature."),
                        spell("Mind Thrust","1",,,,,,,,,,"Mentally deal 2d10 damage to one target."),
                        spell("Mystic Cure","1",,,,,,,,,,"Restore 1d8 + your Wisdom modifier Hit Points to a living creature."),
                        spell("Reflecting Armor","1",,,,,,,,,,"Sheath of mystical force can reflect damage back on foe."),
                        spell("Remove Condition, Lesser","1",,,,,,,,,,"Remove one minor harmful condition affecting a creature."),
                        spell("Share Language","1",,,,,,,,,,"Target understands chosen languages."),
                        spell("Wisp Ally","1",,,,,,,,,,"Create wisp of energy that shines light and distracts and enemy."),
                        spell("Auguary","2","Divination","1 minute","Personal","N/A","N/A","Instantaneous","N/A","N/A","Casting augury can tell you whether a particular action "
                        "will bring good or bad results for you in the immediate future. Casting this spell takes intense personal focus and requires you to spend 1 Resolve Point."
                        "The chance for successfully receiving a meaningful reply is 75%; this roll is made secretly by the GM. A question may be so straightforward that a successful "
                        "result is automatic, or it may be so vague as to have no chance of success. If the augury succeeds, you get one of four results.* Weal (if the action will "
                        "probably bring good results).* Woe (for bad results).* Weal and woe (for both).* Nothing (for actions that have neither especially good nor especially bad "
                        "results).If the augury isn’t successful, you get the “nothing” result. A spellcaster who gets the “nothing” result has no way to tell whether it was the "
                        "consequence of a failed or successful augury.The augury can see only about 30 minutes into the future, so anything that might happen beyond that time frame "
                        "does not affect the result. Thus, the result might not take into account the long-term consequences of a contemplated action. Multiple castings of augury by "
                        "the same creature about the same topic use the same die result as the first casting.","Learn whether and action with be good or bad."),
                        spell("Command Undead","2","Necromancy (sense-dependent)","1 standard action","close (25ft +5/2 levels","N/A","One undead creature","1 day/level","Will negates","Yes","This spell allows you a degree of control over an undead creature. If the target is intelligent, it perceives your words and actions favorably (treat its attitude as friendly). It will not attack you while the spell lasts. You can give the target suggestions, but you must succeed at an opposed Charisma check to convince it to do anything it wouldn’t ordinarily do. (Retries are not allowed.) An intelligent commanded undead never obeys suicidal or obviously harmful suggestions, but it might be convinced that something very dangerous is worth doing.An unintelligent undead creature gets no saving throw against this spell. When you control a mindless being, you can communicate only basic commands, such as “Come here,” “Go there,” “Fight,” “Stand still,” and so on. Unintelligent undead won’t resist suicidal or obviously harmful orders. Any act by you or your apparent allies that threatens the commanded undead (regardless of its Intelligence) breaks the spell. You command the undead creature by voice and it understands you, no matter what language you speak.","Undead creature obeys your commands."),
                        spell("Darkvision","2",,,,,,,,,,"Grant ability to see 60 feet in total darkness."),
                        spell("Daze Monster","2",,,,,,,,,,"Target living creature of CR 5 or lower is dazed."),
                        spell("Fear","2",,,,,,,,,,"Frighten multiple creatures of CR 4 or lower for 1 minute."),
                        spell("Fog Cloud","2",,,,,,,,,,"Create a fog that obscures vision."),
                        spell("Force Blast","2",,,,,,,,,,"Cone deals 2d6 force damage and bull rushes creatures."),
                        spell("Hold Person","2",,,,,,,,,,"Paralyze one humanoid."),
                        spell("Hurl Forcedisk","2",,,,,,,,,,"Disc deals 3d6 force damage to one target then ricochets to other targets, dealing 2d6 force damage."),
                        spell("Inflict Pain","2",,,,,,,,,,"Wracking pain imposes -2 penalty to ability checks, attack rolls, and skill checks on one target."),
                        spell("Mind Thrust","2",,,,,,,,,,"Mentally deal 4d10 damage to one target."),
                        spell("Remove Condition","2",,,,,,,,,,"Remove one moderate harmful condition affecting a creature."),
                        spell("Restoration, Lesser","2",,,,,,,,,,"Dispel magical ability penalty or cure 1d4 ability damage."),
                        spell("See Invisibility","2",,,,,,,,,,"See invisible creatures or objects."),
                        spell("Shield Other","2",,,,,,,,,,"You take half of the target's Hit Point damage."),
                        spell("Status","2",,,,,,,,,,"Monitor condition and position of allies."),
                        spell("Zone of Truth","2",,,,,,,,,,"Creatures within range can't lie."),
                        spell("Bestow Curse","3","Necromancy (curse)","1 standard action","Touch","N/A","One creature","Permanent","Will negates","Yes","You place a "
                        "terrible curse on the target, stealing either its overall competency or its ability to think and act on its feet. Choose one of the following.* "
                        "The target takes a –4 penalty to ability checks, attack rolls, saving throws, and skill checks.* Each turn, the target has a 50""%"" chance to act "
                        "normally; otherwise, it takes no action.You can also invent your own curse (see Afflictions on page 414 for a few ideas), but it should be no more "
                        "powerful than those described above. The curse bestowed by this spell cannot be dispelled, but it can be removed with a break enchantment, miracle, "
                        "remove affliction, or wish spell.Casting this spell doesn’t provoke attacks of opportunity. Bestow curse counters remove affliction",
                        "Target takes -4 penalty to attack rolls, saves, and checks or 50""%"" chanve of not acting on each of its turns."),
                        spell("Charm Monster","3","Enchantment (charm, mind-affecting)","1 standard action","close (25ft +5 ft/2 levels)","N/A","One living creature",
                        "1 day/level","Will negates","Yes","This charm makes a creature regard you as its trusted friend and ally (treat the target’s attitude as friendly). "
                        "If the creature is currently being threatened or attacked by you or your allies, however, it receives a +5 bonus to its saving throw.The spell does not enable "
                        "you to control the charmed creature as if it were an automaton. It is unlikely to attempt to harm you, but it is also unlikely to attack any of its true friends "
                        "or allies. You can try to give the target suggestions, but you must succeed at an opposed Charisma check to convince it to do anything it wouldn’t ordinarily "
                        "do. (Retries of this check are not allowed.) An affected creature never obeys suicidal or obviously harmful suggestions. Any act by you or your apparent allies "
                        "that threatens the charmed creature breaks the spell. You must speak the creature’s language to communicate your suggestions, or else be good at pantomiming",
                        "Make one creature believe it is your ally or one day per level."),
                        spell("Clairaudience/Clairvoyance","3","Divination (scrying)","10 minutes","long (400ft +40ft/level)","N/A","N/A","1 minute/level","N/A","N/A",
                        "You create an invisible magical sensor at a specific location that enables you to hear or see (your choice) almost as if you were there. You don’t need "
                        "line of sight or line of effect to create this sensor in a specific spot within range, but the locale must be either a place that’s familiar to you or an "
                        "obvious location, such as inside a cave whose entrance you can see. The sensor doesn’t move, but you can rotate it in all directions to view the area as "
                        "desired. This spell functions only on the plane of existence you are currently occupying.","Hear or see at a distance for 1 minute per level."),
                        spell("Deep Slumber","3",,,,,,,,,,"Put a number of creatures wjose CRs total 8 or less to sleep".),
                        spell("Dispel Magic","3",,,,,,,,,,,"Cancel one magical spell or effect."),
                        spell("Fear","3",,,,,,,,,,"Targets of CR 8 or lower within a cone are panicked for 1 minutes."),
                        spell("Haste","3",,,,,,,,,,"One creature per level moves and acts faster."),
                        spell("Hologram Memory","3",,,,,,,,,,,"Extract a creature's memory and replay it as a hologram."),
                        spell("Irradiate","3",,,,,,,,,,"Flood area with dangerous radiation."),
                        spell("Psychokinetic Strangulation","3",,,,,,,,,,"Concentrate to immobilize target and deal 3d8 damage per round."),
                        spell("Ray of Exhaustion","3",,,,,,,,,,"Ray makes target exhausted."),
                        spell("Remove Affliction","3",,,,,,,,,,"Neutralize curses, diseases, infestations, poisons, and other harmful conditions affecting a creature."),
                        spell("Resistant Armor, Lesser", "3",,,,,,,,,,"Grant DR 5/- or energy resistance 5 against two energy types."),
                        spell("Slow","3",,,,,,,,,,"One creature per level moves and acts slower."),
                        spell("Speak with Dead","3",,,,,,,,,,"Corpse answers up to six questions."),
                        spell("Suggestion","3",,,,,,,,,,"Compel a target to follow stated course of action."),
                        spell("Synaptic Pulse","3",,,,,,,,,,"Stun all creatures within 20 feet for 1 round."),
                        spell("Tongues","3",,,,,,,,,,"Target can speak and understand any language."),
                        spell("Animated Dead","4","Necromancy","1 standard action","touch","N/A","one or more corpses","instantaneous",
                        "N/A","N/A","This spell turns corpses into undead creatures that obey your spoken commands. The undead can be made"
                        " to follow you, or they can be made to remain in place and attack any creature (or a specific kind of creature) entering"
                        " the area. They remain animated until they are destroyed. A destroyed undead can't be animated again.You can create one or"
                        " more undead creatures with a total CR of no more than half your caster level. You can only create one type of undead with each"
                        " casting of this spell. Creating undead requires special materials worth 1,000 credits x the total CR of the undead created; these" 
                        " materials are consumed as part of casting the spell. The undead you create remain under your control indefinitely. No matter how many"
                        " times you use this spell, however, you can control only a number of undead whose total CR is no greater than your caster level. If you"
                        " exceed this number, all the newly created creatures fall under your control and any excess undead from previous castings become uncontrolled."
                        " You choose which creatures are released. Once released, such undead have no particular feelings of loyalty to you, and in time they may grow in power"
                        " beyond the undead you can create.The corpses you use must be as intact as the typical undead of the type you choose to create. For example, a skeleton can"
                        " be created only from a mostly intact corpse (that has bones) or skeleton. A zombie can be created only from a creature with a physical anatomy.",
                        "Create controlled undead creatures out of target corpses."),
                        spell("Confusion","4",,,,,,,,,,"Targets behave randomly for 1 round per level."),
                        spell("Cosmic Eddy","4",,,,,,,,,,"Whirlwind deals 4d6 damage and knocks creatures prone."),
                        spell("Death Ward","4",,,,,,,,,,"Target gains a +4 bonus to saves against death spells, and is immune to negative energy and gaining negative levels."),
                        spell("Discern Lies","4",,,,,,,,,,"Reveals deliberate falsehoods."),
                        spell("Dismissal","4-5",,,,,,,,,,"Force a creature to return to its native plane."),
                        spell("Divination","4",,,,,,,,,,"Gain useful advice for specific proposed actions."),
                        spell("Enervation","4",,,,,,,,,,"Ray imposes 2 negative levels."),
                        spell("Fear","4",,,,,,,,,,"All targets withing a cone are panicked for 1 minute."),
                        spell("Hold Monster","4",,,,,,,,,,"Paralyze one creature."),
                        spell("Mind Probe","4",,,,,,,,,,"Potentially access a target creature's memories and its knowledge."),
                        spell("Planar Binding","4-6",,,,,,,,,,"Trap an extraplanar creature of CR 4 or lower until it performs a task."),
                        spell("Reincarnate","4",,,,,,,,,,"Bring a target dead creature back to life in a random body"),
                        spell("Remove Radioactivity","4",,,,,,,,,,"Remove ongoing radiation effect from a creature or object."),
                        spell("Resistant Armor","4",,,,,,,,,,"Grant DR 10/- or energy resistance 10 to three energy types."),
                        spell("Restoration","4",,,,,,,,,,"Restores ability score drain and negative levels."),
                        spell("Telepathic Bond","4",,,,,,,,,,"Link allows allies to communicate."),
                        spell("Break Enchantment","5","Abjuration","1 minute","close (25ft +5ft/2levels)","N/A","Up to one creature per level. no two of which can be more than 30 ft apart.",
                        "Instantaneous","N/A","N/A","This spell frees victims from curses, enchantments, and transmutations. Break enchantment can reverse even an instantaneous effect. "
                        "For each such effect, you attempt a caster level check (1d20 + your caster level, maximum +15) against a DC equal to 11 + the caster level of the effect. "
                        "Success means that the creature is free of the spell, curse, or effect. For a cursed magic item, the DC of the caster level check is equal to the DC of the "
                        "curse.If the spell is one that can’t be dispelled by dispel magic, break enchantment works only if that spell is 5th level or lower. If the effect comes from "
                        "a permanent magic item, break enchantment doesn’t remove the curse from the item but it does free the victim from the item's effects.",
                        "Free creatures from curses, enchantments, and transmutations."),
                        spell("Call Cosmos","5","Evocation","1 standard action","Long (400ft + 40ft/level","Cylinder (ft radius, 40 ft high)","N/A","1 round/level","N/A","Yes",
                        "You evoke a vertical column of dangerous material from across the universe that rains down upon creatures in the area. This matter is made up of bits "
                        "of burning stars and chunks of frozen comets, and it deals 4d6 fire damage and 3d6 cold damage to every creature in the area. This damage occurs only "
                        "once, when the spell is cast. For the spell’s remaining duration, the fallen starstuff makes the entire area difficult terrain, and thick, swirling "
                        "clouds of particulate space matter magically block vision. This obscures all sight beyond 5 feet, including darkvision and other vision-based senses "
                        "(including vision-based blindsight and sense through), but doesn’t prevent blindsense. A creature within 5 feet of its attacker has concealment (attacks "
                        "have a 20% miss chance). Creatures farther away have total concealment (50% miss chance, and the attacker can’t use sight to locate the target). "
                        "Additionally, the swirling cosmic particles are distracting to spellcasters in the area, who have a 20% chance of losing any spell they attempt to cast "
                        "in the area. At the end of the duration, the starstuff disappears, leaving no aftereffects (other than the damage dealt).",
                        "Rain cosmic particles on targets, dealing 4d6 fire damage and 3d6 cold damage."),
                        spell("Command, Greater","5","Enchantment (compulsion, language-dependent, mind-affecting)","1 standard action","close (25ft +5ft/2 levels)","N/A",
                        "Up to one creature/level, no two of which can be more than 30ft. apart","1 round/level","Will negates","Yes",
                        "You give the target one of the following commands, which it obeys to the best of its ability at its "
                        "earliest opportunity. If the target can’t carry out your command on its next turn, the spell automatically fails. Approach: The target moves toward you as "
                        "quickly and directly as possible for 1 round, taking no other actions and triggering reactions (such as attacks of opportunity) for this movement as normal. "
                        "Drop: The target drops whatever it is holding. It can’t pick up any dropped item until its next turn. Fall: The target falls to the ground and remains prone "
                        "for 1 round. It can otherwise act normally.Flee: The target moves away from you as quickly and directly as possible for 1 round, taking no other actions and "
                        "provoking reactions (such as attacks of opportunity) for this movement as normal. Halt: The target is dazed for 1 round.",
                        "One creature per level obeys select command for 1 round per level."),
                        spell("Commune With Nature","5",,,,,,,,,,"Learn about terrain for 1 mile per level."),
                        spell("Contact Other Plane","5",,,,,,,,,,"Ask questions of extraplanar entity."),
                        spell("Crush Skull","5",,,,,,,,,,"Deal 18d8 damage to living creature's head."),
                        spell("Dispel Magic, Greater","5",,,,,,,,,,"Cancel multiple spells or effects."),
                        spell("Dominate Person","5",,,,,,,,,,"Control humanoid telepathically."),
                        spell("Feeblemind","5",,,,,,,,,,"Target's Intelligence and Charisma scores drop to 1."),
                        spell("Modify Memory","5",,,,,,,,,,"Change 5 minutes of target's memories."),
                        spell("Mystic Cure, Mass","5-6",,,,,,,,,,"Restore 3d8 + your Wisdom modifier Hit Points to one living creature per level."),
                        spell("Raise Dead","5",,,,,,,,,,"Restore life to a creature that died no more than 1 day per level ago."),
                        spell("Remove Condition, Greater","5",,,,,,,,,,"Remove all harmful conditions affecting a creature."),
                        spell("Resistant Aegis","5",,,,,,,,,,"Grant up to 10 creatures DR 5/- or energy resistance 5 to all energy types."),
                        spell("Retrocognition","5",,,,,,,,,,"Gain psychic impressions of past events in a certain location."),
                        spell("Synaptic Pulse, Greater","5",,,,,,,,,,"Stun all creatures withing 20 feet for 1d4 rounds."),
                        spell("Telepathy","5",,,,,,,,,,"Communicate mentally with any creatures within 100 feet."),
                        spell("Waves of Fatigue","5",,,,,,,,,,"Several targets become fatigued."),
                        spell("Control Gravity","6",,,,,,,,,,"Alter gravity in an area."),
                        spell("Control Undead","6",,,,,,,,,,"Undead creatures follow your commands and don't attack you."),
                        spell("Enshrining Refuge","6",,,,,,,,,,"Targets can't attack or be attacked, but can exist comfortably."),
                        spell("Ethereal Jaunt","6",,,,,,,,,,"You become ethereal for 1 round per level."),
                        spell("Flesh to Stone","6",,,,,,,,,,"Turn a creature into a statue."),
                        spell("Gravitational Singularity","6",,,,,,,,,,"Particle with infinite density pulls creatures and objects into it, dealing 12d6 damage each round to those inside."),
                        spell("Inflict Pain, Mass","6",,,,,,,,,,"Wracking pain imposes -2 penalty to ability checks, attack rolls and skill checks on one target per level."),
                        spell("Planar Barrier","6",,,,,,,,,,"Seal an area against all planar trabel into or within it."),
                        spell("Plane Shift","6",,,,,,,,,,"As many as eight creatures travel to another plane you choose."),
                        spell("Psychic Surgery","6",,,,,,,,,,"Cure all Intelligene, Wisdom, and Charisma damage and drain, plus remove other mental affilictions and conditions."),
                        spell("Regenerate","6",,,,,,,,,,"Grow back target's severed limbs, restore 12d8 Hit Points, and remove exhaustion and fatigue."),
                        spell("Resistant Armor, Greater","6",,,,,,,,,,"Grant DR 15/- or energy resistance 15 against four energy types."),
                        spell("Shadow Walk","6",,,,,,,,,,"Step into a shadowy realm to travel to a destination rapidly."),
                        spell("Snuff Life","6",,,,,,,,,,"Instantly kill or massively damage one creature per 2 caster levels, depending on targets' CRs."),
                        spell("Subjective Reality","6",,,,,,,,,,"You convince yourself one creature or object is an illusion."),
                        spell("Suggestion, Mass","6",,,,,,,,,,"Compel one target per level to follow stated course of action."),
                        spell("Telepathic Jaunt","6",,,,,,,,,,"Use your telepathic bond with a creature to teleport to its location."),
                        spell("True Seeing","6",,,,,,,,,,"Target can see things as they really are."),
                        spell("Vision","6",,,,,,,,,,"Answer a question about a person, place or object.")};
    spell technolist[] ={ spell("Dancing Lights", "0",,,,,,,,,,"Create and direct up to four lights."),
                        spell("Daze","0",,,,,,,,,,"Humanoid creature of CR 3 or lower is dazed."),
                        spell("Detect Affliction","0",,,,,,,,,,"Determine whether a creature or object has been poisoned, is diseased, is cursed, or is suffering a similar affliction."),
                        spell("Detect Magic","0",,,,,,,,,,"Detect spells and magic items within 60 feet."),
                        spell("Energy Ray","0",,,,,,,,,,"Ray deals 1d3 acid, cold, ekectricity, or fire damage."),
                        spell("Ghost Sound","0",,,,,,,,,,"Create minor illusory sounds."),
                        spell("Mending","0",,,,,,,,,,"Restore 1d4 Hit Points to an object or construct."),
                        spell("Psychokinetic Hand","0",,,,,,,,,,"Telekinetically move an object of 1 bulk or less."),
                        spell("Telepathic Message","0",,,,,,,,,,"Send a short telepathic message and hear simple telepathic replies."),
                        spell("Token Spell","0",,,,,,,,,,"Perform simple magical effects."),
                        spell("Transfer Charge","0",,,,,,,,,,"Move charges from one power source to another source of the same type."),
                        spell("Comprehend Languages","1",,,,,,,,,,"You understand all spoken, signed, and written or tactile languages."),
                        spell("Detect Radiation","1",,,,,,,,,,"Detect radiation within 120 feet."),
                        spell("Detect Tech","1",,,,,,,,,,"Detect technological items with charges or that replenish charges within 60 feet."),
                        spell("Disguise Self","1",,,,,,,,,,"Change your appearance."),
                        spell("Erase","1",,,,,,,,,,"Remove writings of either magical or mundane nature."),
                        spell("Flight","1-6",,,,,,,,,,"One creature or object per level falls slowly."),
                        spell("Grease","1",,,,,,,,,,"Make a 10-ft. square or one object slippery."),
                        spell("Hold Portal","1",,,,,,,,,,"Hold a door shut."),
                        spell("Holographic Image","1-6",,,,,,,,,,"Creat a silent hologram of your design."),
                        spell("Identify","1",,,,,,,,,,"Gain +10 bonus to identify items of a magic or technoloigcal nature."),
                        spell("Jolting Surge","1",,,,,,,,,,"Touch deals 4d6 electricity damage."),
                        spell("Keen Senses","1",,,,,,,,,,"Target gains low-light vision and +2 bonus to Perception checks."),
                        spell("Life Bubble","1",,,,,,,,,,"Encase targeted creatures with a shell of tolerable atmosphere."),
                        spell("Magic Missile","1",,,,,,,,,,"Two missles deal 1d4+1 force damage."),
                        spell("Overheat","1",,,,,,,,,,"Deal 2d8 fire damage to creatures in cone."),
                        spell("Supercharge Weapon","1",,,,,,,,,,"Touched weapon deals extra damage."),
                        spell("Unseen Servant","1",,,,,,,,,,"Invisible force obeys your commands."),
                        spell("Caustic Conversion","2","Evocation (acid)","1 standard action","Medium (100ft +10ft/level)","N/A","One creature or object","1 round + 1 round/3 levels",
                        "N/A","Yes","You fling magical nanites that convert water vapor around your target into deadly acid. Make a ranged attack roll against your target’s EAC. "
                        "If you hit, the target takes 4d4 acid damage and it takes 5 additional acid damage at the end of its turn each round for the spell’s duration",
                        "Fling magical nanites as a ranged attack that deals 4d4 acid damage to one target, plus 5 additional damage in subsequent rounds."),
                        spell("Command Undead","2",,,,,,,,,,"Undead creature obeys your commands."),
                        spell("Darkvision","2",,,,,,,,,,"Grant ability to see 60 feet in total darkness."),
                        spell("Daze Monster","2",,,,,,,,,,"Target living creature of CR 5 or lower is dazed."),
                        spell("Fog Cloud","2",,,,,,,,,,"Create a fog that obscures vision."),
                        spell("Implant Data","2",,,,,,,,,,"Embed one piece of data per level in a target computer or system."),
                        spell("Inject Nanobots","2",,,,,,,,,,"Touch deals 4d8 damage to target and causes the confused condistion."),
                        spell("Invisibility","2",,,,,,,,,,"Target is invisible for 1 minute per level or until it attacks."),
                        spell("Knock","2",,,,,,,,,,"Opens a locked or magically sealed door."),
                        spell("Logic Bomb","2",,,,,,,,,,"Target computer deals 6d6 energy damage to the first creature that tries and fails to use it."),
                        spell("Make Whole","2",,,,,,,,,,"Restore 5d6 Hit Points to an object or construct."),
                        spell("Microbot Assault","2",,,,,,,,,,"Cloud of tiny robots harasses creatures within it."),
                        spell("Mirror Image","2",,,,,,,,,,"Create decoy duplicates of yourself."),
                        spell("Recharge","2",,,,,,,,,,"Replinish charges in a battery or item capable of holding charges."),
                        spell("Security Seal","2",,,,,,,,,,"Magically lock a portal, a container, or a security system."),
                        spell("See Invisibility","2",,,,,,,,,,"See invisible creatures or objects."),
                        spell("Spider Climb","2",,,,,,,,,,"Grant ability to walk on walls and ceilings."),
                        spell("Arcane Sight","3","Divination","1 standard action","personal","N/A","N/A","1 minute/level","N/A","N/A","This spell allows you to see magic "
                        "sources within 120 feet of you. The effect is similar to that of a detect magic spell, but arcane sight does not require concentration and discerns "
                        "information more quickly.You know the location and caster level of all magic sources within your sight. If the magic sources are in line of sight, you "
                        "can attempt a DC 28 Mysticism check (one check per source) to determine the school of magic involved in each source.If you concentrate on a specific "
                        "creature within 120 feet of you as a standard action, you can determine whether it has any spellcasting or spell-like abilities and the caster level "
                        "of the most powerful spell or spell-like ability the creature currently has available for use. As with detect magic, you can use this spell to identify "
                        "the properties of magic items, but not of artifacts","Magical sources become visible to you."),
                        spell("Arcing Surge","3","evocation (electricity)","1 standard action","120 ft","line-shaped burst","N/A","Instantaneous","Reflex half","Yes","You cause an "
                        "electrical device in your possession to surge in power and unleash a line of electricity from the massive oversurge. This deals 10d6 electricity damage "
                        "to all creatures and objects in the area.","Deal 10d6 electricity damage in a 120-foot line."),
                        spell("Clairaudience/Clairvoyance","3","Divination (scrying)","10 minutes","long (400ft +40ft/level)","N/A","N/A","1 minute/level","N/A","N/A",
                        "You create an invisible magical sensor at a specific location that enables you to hear or see (your choice) almost as if you were there. You don’t need "
                        "line of sight or line of effect to create this sensor in a specific spot within range, but the locale must be either a place that’s familiar to you or an "
                        "obvious location, such as inside a cave whose entrance you can see. The sensor doesn’t move, but you can rotate it in all directions to view the area as "
                        "desired. This spell functions only on the plane of existence you are currently occupying.","Hear or see at a distance for 1 minute per level."),
                        spell("Discharge","3",,,,,,,,,,"Disrupts or depowers one target technological item or construct."),
                        spell("Dispel Magic","3",,,,,,,,,,"Cancel one magical spell or effect."),
                        spell("Displancement","3",,,,,,,,,,"Attacks miss target 50% of the time."),
                        spell("Entropic Grasp","3",,,,,,,,,,"Touch decays a construct or nonmagical manufactured item once per round per level."),
                        spell("Explosive Blast","3",,,,,,,,,,"Deal 9d6 fire damage to creatures in a 20-foot radius."),
                        spell("Handy Junkbot","3",,,,,,,,,,"Create a temporary robot made of junk to perform Computers, Engineering, Piloting, and Sleight of Hand tasks."),
                        spell("Haste","3",,,,,,,,,,"One creature per level moves and acts faster."),
                        spell("Healing Junkbot","3",,,,,,,,,,"Robot made of junk can perform Medicine tasks and drag unconscious creature to safety."),
                        spell("Instant Virus","3",,,,,,,,,,"Inflict technological vonstruct with disease."),
                        spell("Irradiate","3",,,,,,,,,,"Flood area with dangerous radiation."),
                        spell("Nondetection","3",,,,,,,,,,"Hide target from divination and surveillance."),
                        spell("Probablility Prediction","3",,,,,,,,,,"Reroll one attack roll, save, or check."),
                        spell("Resistant Armor, Lesser", "3",,,,,,,,,,"Grant DR 5/- or energy resistance 5 against two energy types."),
                        spell("Slow","3",,,,,,,,,,"One creature per level moves and acts slower."),
                        spell("Tongues","3",,,,,,,,,,"Target can speak and understand any language."),
                        spell("Animated Dead","4","Necromancy","1 standard action","touch","N/A","one or more corpses","instantaneous",
                        "N/A","N/A","This spell turns corpses into undead creatures that obey your spoken commands. The undead can be made"
                        " to follow you, or they can be made to remain in place and attack any creature (or a specific kind of creature) entering"
                        " the area. They remain animated until they are destroyed. A destroyed undead can't be animated again.You can create one or"
                        " more undead creatures with a total CR of no more than half your caster level. You can only create one type of undead with each"
                        " casting of this spell. Creating undead requires special materials worth 1,000 credits x the total CR of the undead created; these" 
                        " materials are consumed as part of casting the spell. The undead you create remain under your control indefinitely. No matter how many"
                        " times you use this spell, however, you can control only a number of undead whose total CR is no greater than your caster level. If you"
                        " exceed this number, all the newly created creatures fall under your control and any excess undead from previous castings become uncontrolled."
                        " You choose which creatures are released. Once released, such undead have no particular feelings of loyalty to you, and in time they may grow in power"
                        " beyond the undead you can create.The corpses you use must be as intact as the typical undead of the type you choose to create. For example, a skeleton can"
                        " be created only from a mostly intact corpse (that has bones) or skeleton. A zombie can be created only from a creature with a physical anatomy.",
                        "Create controlled undead creatures out of target corpses."),
                        spell("Arcane Eye","4","Divination (scrying)","10 minutes","Planetary","N/A","N/A","1 min/level","N/A","N/A","You create an invisible magical sensor that sends"
                         "you visual information. The sensor appears at any point within line of sight, but it can then travel beyond your line of sight without hindrance. An arcane eye"
                         " travels at 30 feet per round (300 feet per minute) if viewing an area ahead as a humanoid would (primarily looking at the floor) or 10 feet per round (100 feet"
                         " per minute) if examining the ceiling and walls as well as the floor ahead. The arcane eye sees exactly as you would see if you were there.The arcane eye can "
                         "travel in any direction as long as the spell lasts. Solid barriers block its passage, but it can pass through a hole or space as small as 1 inch in diameter. "
                         "The arcane eye can’t enter another plane of existence, even through Drift travel or a magical gate or similar magical portal.You must concentrate to use an "
                         "arcane eye. If you do not concentrate, the sensor is inert until you concentrate again",
                         "Invisible floating eye moves 30 feet per round and sends you visual information."),
                        spell("Corrosive Haze","4",,,,,,,,,,"Cloud deals 4d8 acid damage per round, plus 10 additional damage."),
                        spell("Creation","4-5",,,,,,,,,,"Create one object made of vegetable matter."),
                        spell("Destruction Protocol","4",,,,,,,,,,"Turn nonhostile technological construct against your foes."),
                        spell("Dimension Door","4",,,,,,,,,,"Teleport a short distance."),
                        spell("Dismissal","4-5",,,,,,,,,,"Force a creature to return to its native plane."),
                        spell("Invisibility, Greater","4",,,,,,,,,,"Target is invisible for 1 round per level, even if it attacks."),
                        spell("Overload Systems","4",,,,,,,,,,"Target creature has a 50% chance to lose each action."),
                        spell("Planar Binding","4-6",,,,,,,,,,"Traps an extraplanar creature of CR 4 or lower until it performs a task."),
                        spell("Remove Radioactivity","4",,,,,,,,,,"Remove ongoing radiation effects from a creature or object."),
                        spell("Resilient Sphere","4",,,,,,,,,,"Force globe protects but traps one target."),
                        spell("Resistant Armor","4",,,,,,,,,,"Grant DR 10/- or energy resistance 10 to three energy types."),
                        spell("Rewire Flesh","4",,,,,,,,,,"Turn target partially into a robot, dealing 3d6 damager per round and reducing speed."),
                        spell("Soothing Protocol","4",,,,,,,,,,"Calm a target hostile technological construct."),
                        spell("Wall of Fire","4",,,,,,,,,,"Blazing curtain deals 2d6 fire damage out to 10 feet and 1d6 fire damage out to 20 feet; passing through the wall deals 5d6 fire damage."),
                        spell("Break Enchantment","5","Abjuration","1 minute","close (25ft +5ft/2levels)","N/A","Up to one creature per level. no two of which can be more than 30 ft apart.",
                        "Instantaneous","N/A","N/A","This spell frees victims from curses, enchantments, and transmutations. Break enchantment can reverse even an instantaneous effect. "
                        "For each such effect, you attempt a caster level check (1d20 + your caster level, maximum +15) against a DC equal to 11 + the caster level of the effect. "
                        "Success means that the creature is free of the spell, curse, or effect. For a cursed magic item, the DC of the caster level check is equal to the DC of the "
                        "curse.If the spell is one that can’t be dispelled by dispel magic, break enchantment works only if that spell is 5th level or lower. If the effect comes from "
                        "a permanent magic item, break enchantment doesn’t remove the curse from the item but it does free the victim from the item's effects.",
                        "Free creatures from curses, enchantments, and transmutations."),
                        spell("Contact Other Plane","5",,,,,,,,,,"Ask questions of an extraplanar entity, with questionable results."),
                        spell("Control Machines","5",,,,,,,,,,"Command technological constructs within range telepathically."),
                        spell("Dispel Magic, Greater","5",,,,,,,,,,"Cancel multiple magical spells or effects."),
                        spell("Heat Leech","5",,,,,,,,,,"Deal 13d8 cold damage to creatures in a cone."),
                        spell("Holographic Terrain","5",,,,,,,,,,"Create a large hologram that depicts terrain and structures."),
                        spell("Mislead","5",,,,,,,,,,"Make yourself invisible and create an illusory double of your likeness."),
                        spell("Passwall","5",,,,,,,,,,"Create a passage through most walls."),
                        spell("Private Sanctum","5",,,,,,,,,,"Prevent anyone from viewing or scrying an area for 24 hours."),
                        spell("Prying Eyes","5",,,,,,,,,,"Twenty floating eyes scout for you."),
                        spell("Resistant Aegis","5",,,,,,,,,,"Grant up to 10 creatures DR 5/- or energy resistance 5 to all energy types."),
                        spell("Synapse Overload","5",,,,,,,,,,"Target takes 18d8 damage and is staggered for 1 minute."),
                        spell("Telekinesis","5",,,,,,,,,,"Move an object, attack creatures, or hurl objects or creatures with your mind."),
                        spell("Teleport","5",,,,,,,,,,"Instantly teleport as far as 2,000 miles."),
                        spell("Unwilling Guardian","5",,,,,,,,,,"Charm a target into protecting you during combat."),
                        spell("Wall of Force","5",,,,,,,,,,"Invisible wall is difficult to destroy."),
                        spell("Battle Junkbot","6","Transmutation","1 round","Touch","N/A","At least 1 bulk of inert electronic equipment; see text.","1 round/level","N/A","N/A","You turn "
                        "a pile of technological junk into a vicious robot that can hunt down and attack your enemies. You must target inert, nonworking electronic equipment of at least 1 "
                        "bulk. Valid targets include a large broken computer system, nonworking or unconnected computer or robot parts, a destroyed robot or another such trashed mechanical "
                        "system, or any related electronic components or combination of the above as long as the junk is found in a large enough quantity. Creating a battle junkbot also "
                        "requires one ultra-capacity battery. Casting this spell drains all of the battery’s charges.While casting this spell, you use your magic and technological know-"
                        "how to rearrange the junked parts and infuse them with aggression and martial skills. A battle junkbot is Small, its KAC and EAC are each equal to 15 + your "
                        "technomancer level, it has hardness 15, and it has a number of Hit Points equal to half of your own (but no Stamina Points). It uses your saving throw bonuses "
                        "when it is the target of spells and other targeted effects. It has a land speed of 30 feet and a fly speed of 15 feet with average maneuverability. For purposes "
                        "of spells and effects that target the junkbot, it is treated as a construct with the magical and technological subtypes.The battle junkbot has four hands. It is "
                        "treated as if it had the Deadly Aim and Improved Combat Maneuver (Bull Rush, Grapple, Trip) feats. It has an attack bonus equal to 6 + your technomancer level; "
                        "in one hand it wields a special buzzblade dagger that deals 6d8+6 damage instead of its normal damage, and a second hand carries a special light laser pistol "
                        "that deals 6d6 damage instead of its normal damage. Damage from the junkbot’s special weapons counts as magic for the purpose of overcoming damage reduction. "
                        "You can give new basic commands to your battle junkbot telepathically on your turn as a move action, and the junkbot can take actions as if it were a normal "
                        "creature. You are aware when the robot has made an attack or combat maneuver and whether or not it was successful, as well as when the battle junkbot has been "
                        "attacked, has taken damage, or is destroyed, but you can perceive nothing else through this basic telepathic link. When the battle junkbot is destroyed or this "
                        "spell ends, the electronic equipment you used to create the junkbot falls apart into refuse, its circuitry fried beyond anything recognizable. You cannot use "
                        "this refuse as a target to create another junkbot.","Create a temporary robot from random junk, turning it into a deadly combatant."),
                        spell("Chain Surge","6","Evocation (electricity)","1 standard action","long (400ft +40ft/level)","N/A",
                        "One primary target and up tp 10 secondary targets, no two of which can be more than 30 ft from the primary target.","Instantaneous",
                        "Reflex half, see text","Yes","Choose a primary target as well as up to 10 secondary targets within 30 feet of the primary target. The primary target "
                        "must be carrying or wielding some kind of equipment that uses electricity. This spell causes the primary target’s electrical equipment to surge with "
                        "deadly electricity, which arcs out to strike the secondary targets, dealing 13d12 electricity damage to all targets chosen. If the primary target fails "
                        "its Reflex save, the spell also shorts out one of that target’s electrical items (your choice) for 1 round, meaning the primary target can’t use it for "
                        "that period. If the primary target negates the effect entirely (such as with evasion), the secondary targets also suffer no effects.",
                        "Deal 13d12 electricity damage to primary target and up to 10 secondary targets; one of the primary target's electrical devices stops functioning for 1 round."),
                        spell("Control Gravity","6",,,,,,,,,,"Alter gravity in an area."),
                        spell("Control Undead","6",,,,,,,,,,"Undead creatures follow your commands and don't attack you."),
                        spell("Discharge, Greater","6",,,,,,,,,,"Disrupts or depowers multiple technological items or constructs."),
                        spell("Disintegrate","6",,,,,,,,,,"Ray reduces one creature or object to dust."),
                        spell("Ethereal Jaunt","6",,,,,,,,,,"You become ethereal for 1 round per level."),
                        spell("Interplanetary Teleport","6",,,,,,,,,,"Teleport between planets."),
                        spell("Invisibility, Mass","6",,,,,,,,,,"Multiple targets are invisible for 1 minute per level or until one target attacks or moves away from other targets affected by spell."),
                        spell("Planar Barrier","6",,,,,,,,,,"Seal an area against all planar travel into or within it."),
                        spell("Plane Shift","6",,,,,,,,,,"As many as eight creatures travel to another plane of your choice."),
                        spell("Resistant Armor, Greater","6",,,,,,,,,,,"Grant DR 15/- or energy resistance 15 against four energy types."),
                        spell("Rewire Flesh, Mass","6",,,,,,,,,,"Deal 3d6 damager per round and reducing targets' speed during that time."),
                        spell("Shadow Walk","6",,,,,,,,,,"Step into a shadowy realm to travel to a destination rapidly."),
                        spell("Shadowy Fleet","6",,,,,,,,,,"Illusion of starships deals 3d6 piercing damage and 3d6 fire damage to all creatures in affected area."),
                        spell("Sympathetic Vibration","6",,,,,,,,,,"Deal 2d10 damage per round to freestanding structure."),
                        spell("Terraform","6",,,,,,,,,,"Alter terrain and climate."),
                        spell("True Seeing","6",,,,,,,,,,"Target can see things as they really are."),
                        spell("Veil","6",,,,,,,,,,"Change appearance of a group of creatures."),
                        spell("Wall of Steel","6",,,,,,,,,,"Wall has 45 Hit Points per inch of thickness and hardness 15.")};
    
    ofstream SpellList;
    SpellList.open("test.docx");
    SpellList.close();
    return 0;
}